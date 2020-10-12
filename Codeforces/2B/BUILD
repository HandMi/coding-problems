cc_library(
    name = "2B",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "2B_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//2B",
        "@gtest//:gtest_main",
    ],
)
