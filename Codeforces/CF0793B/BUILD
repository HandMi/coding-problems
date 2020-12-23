cc_library(
    name = "CF0793B",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "CF0793B_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//Codeforces/CF0793B",
        "@gtest//:gtest_main",
    ],
    data = glob(["data/*.txt"]),
)

cc_binary(
    name = "CF0793B_bin",
    deps = [
        "//Codeforces/CF0793B",
    ],
)
