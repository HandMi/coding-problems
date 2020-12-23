cc_library(
    name = "PEP036",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "PEP036_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//ProjectEulerPlus/PEP036",
        "@gtest//:gtest_main",
    ],
)

cc_binary(
    name = "PEP036_bin",
    deps = [
        "//ProjectEulerPlus/PEP036",
    ],
)
