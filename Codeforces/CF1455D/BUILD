cc_library(
    name = "CF1455D",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "CF1455D_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//Codeforces/CF1455D",
        "@gtest//:gtest_main",
    ],
    data = glob(["data/*.txt"]),
)

cc_binary(
    name = "CF1455D_bin",
    deps = [
        "//Codeforces/CF1455D",
    ],
)
