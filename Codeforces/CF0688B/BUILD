cc_library(
    name = "CF0688B",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "CF0688B_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//Codeforces/CF0688B",
        "@gtest//:gtest_main",
    ],
    data = glob(["data/*.txt"]),
)

cc_binary(
    name = "CF0688B_bin",
    deps = [
        "//Codeforces/CF0688B",
    ],
)
