cc_library(
    name = "CF0008B",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "CF0008B_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//Codeforces/CF0008B",
        "@gtest//:gtest_main",
    ],
)

cc_binary(
    name = "CF0008B_bin",
    deps = [
        "//Codeforces/CF0008B",
    ],
)
