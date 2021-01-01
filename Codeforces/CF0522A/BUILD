cc_library(
    name = "CF0522A",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "CF0522A_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//Codeforces/CF0522A",
        "@gtest//:gtest_main",
    ],
    data = glob(["data/*.txt"]),
)

cc_binary(
    name = "CF0522A_bin",
    deps = [
        "//Codeforces/CF0522A",
    ],
)
