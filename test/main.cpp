#include <docker.hpp>
#include <gtest/gtest.h>

TEST(DockerConnection, PingDaemon) {
    dockerxx::Docker docker;

    ASSERT_EQ(docker.ping(), "OK");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}