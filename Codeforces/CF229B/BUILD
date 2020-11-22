cc_library(
    name = "CF229B",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "CF229B_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//Codeforces/CF229B",
        "@gtest//:gtest_main",
    ],
    data = glob(["data/*.txt"]),
)

cc_binary(
    name = "CF229B_bin",
    deps = [
        "//Codeforces/CF229B",
    ],
)
