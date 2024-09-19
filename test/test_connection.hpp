#ifndef DOCKERXX_TEST_CONNECTION_HPP
#define DOCKERXX_TEST_CONNECTION_HPP

#include <gtest/gtest.h>
#include <docker.hpp>
#include "credential.hpp"

TEST(Connection, LocalDaemonPing) {
    dockerxx::Docker docker;

    ASSERT_EQ(docker.ping(), "OK");
}

TEST(Connection, RemoteDaemonPingNoAuthentication) {
    dockerxx::Docker docker = dockerxx::Docker(REMOTE_DAEMON_ADDRESS);

    ASSERT_EQ(docker.ping(), "OK");
}

#endif /* DOCKERXX_TEST_CONNECTION_HPP */