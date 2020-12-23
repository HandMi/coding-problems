cc_library(
    name = "CF0131D",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "CF0131D_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//Codeforces/CF0131D",
        "@gtest//:gtest_main",
    ],
)

cc_binary(
    name = "CF0131D_bin",
    deps = [
        "//Codeforces/CF0131D",
    ],
)
