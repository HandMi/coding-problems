cc_library(
    name = "CF0330B",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "CF0330B_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//Codeforces/CF0330B",
        "@gtest//:gtest_main",
    ],
    data = glob(["data/*.txt"]),
)

cc_binary(
    name = "CF0330B_bin",
    deps = [
        "//Codeforces/CF0330B",
    ],
)
