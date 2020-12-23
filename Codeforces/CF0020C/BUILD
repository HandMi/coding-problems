cc_library(
    name = "CF0020C",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "CF0020C_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//Codeforces/CF0020C",
        "@gtest//:gtest_main",
    ],
    data = glob(["data/*.txt"]),
)

cc_binary(
    name = "CF0020C_bin",
    deps = [
        "//Codeforces/CF0020C",
    ],
)
