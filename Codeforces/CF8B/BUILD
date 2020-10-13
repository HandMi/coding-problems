cc_library(
    name = "CF8B",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "CF8B_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//Codeforces/CF8B",
        "@gtest//:gtest_main",
    ],
)

cc_binary(
    name = "CF8B_bin",
    deps = [
        "//Codeforces/CF8B",
    ],
)