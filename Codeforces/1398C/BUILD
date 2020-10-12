cc_library(
    name = "1398C",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "1398C_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//Codeforces/1398C",
        "@gtest//:gtest_main",
    ],
)

cc_binary(
    name = "1398C_bin",
    deps = [
        "//Codeforces/1398C",
    ],
)