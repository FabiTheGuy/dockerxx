#ifndef DOCKERXX_DOCKER_HPP
#define DOCKERXX_DOCKER_HPP

#include <curl/curl.h>
#include <string>


namespace dockerxx {

    class Docker {

        /* Member Variables */
        private:
            CURL* m_curl = nullptr;
            bool m_remote_connection;
            std::string m_uri;

        /* Constructors */
        public:
            Docker();
            explicit Docker(std::string& uri);

        /* Member Functions */
        private:
            std::string request(const std::string& path);

        public:
            std::string ping();

        /* Static Functions */
        private:
            static size_t write_data(void* ptr, size_t size, size_t nmemb, std::string* userp);

    };

} /* namespace dockerxx */

#endif /* DOCKERXX_DOCKER_HPP */