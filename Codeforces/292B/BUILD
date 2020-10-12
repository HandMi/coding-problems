cc_library(
    name = "292B",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "292B_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//292B",
        "@gtest//:gtest_main",
    ],
)

cc_binary(
    name = "292B_exe",
    deps = [
        "//292B",
    ],
)