#ifndef DOCKERXX_DOCKER_HPP
#define DOCKERXX_DOCKER_HPP

#include <curl/curl.h>
#include <string>


namespace dockerxx {

    class Docker {

        private:
            CURL* m_curl = nullptr;
            bool m_remote_connection;
            std::string m_url;

            std::string request(const std::string& path);
            static size_t write_data(CURL* ptr, size_t size, size_t nmemb, std::string* userp);

        public:
            Docker();
            explicit Docker(std::string url);
            std::string ping();

    };

} /* namespace dockerxx */

#endif /* DOCKERXX_DOCKER_HPP */