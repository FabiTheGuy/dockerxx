#include <include/docker.hpp>
#include <stdexcept>
#include <utility>

using namespace dockerxx;

/* Constructors */
Docker::Docker() { this->m_remote_connection = false; }

Docker::Docker(std::string url) {
    this->m_remote_connection = true;
    this->m_url = std::move(url);
}

/* Member functions */
std::string Docker::request(const std::string &path) {
    CURLcode response_code;
    std::string response_data;

    if (path.empty()) {
        throw std::invalid_argument("Path is empty");
    }

    this->m_curl = curl_easy_init();

    if (this->m_remote_connection) {
        curl_easy_setopt(this->m_curl, CURLOPT_URL, std::string(this->m_url + path).c_str());
    } else {
        curl_easy_setopt(this->m_curl, CURLOPT_URL, std::string("http://localhost" + path).c_str());
        curl_easy_setopt(this->m_curl, CURLOPT_UNIX_SOCKET_PATH,
                         std::string("/var/run/docker.sock").c_str());
    }

    curl_easy_setopt(this->m_curl, CURLOPT_WRITEFUNCTION, Docker::write_data);
    curl_easy_setopt(this->m_curl, CURLOPT_WRITEDATA, &response_data);

    response_code = curl_easy_perform(this->m_curl);

    if (response_code != CURLE_OK) {
        throw std::runtime_error("curl_easy_perform() failed: " +
                                 std::string(curl_easy_strerror(response_code)));
    }

    curl_easy_cleanup(this->m_curl);

    return response_data;
}

std::string Docker::ping() { return request("/_ping"); }

/* Static functions */
size_t Docker::write_data(CURL *ptr, size_t size, size_t nmemb, std::string *userp) {
    size_t real_size = size * nmemb;

    userp->append(static_cast<char *>(ptr), real_size);

    return real_size;
}