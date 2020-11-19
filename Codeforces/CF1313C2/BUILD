cc_library(
    name = "CF1313C2",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "CF1313C2_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//Codeforces/CF1313C2",
        "@gtest//:gtest_main",
    ],
    data = glob(["data/*.txt"]),
)

cc_binary(
    name = "CF1313C2_bin",
    deps = [
        "//Codeforces/CF1313C2",
    ],
)
