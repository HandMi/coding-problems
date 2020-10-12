cc_library(
    name = "131D",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "131D_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//Codeforces/131D",
        "@gtest//:gtest_main",
    ],
)

cc_binary(
    name = "131D_bin",
    deps = [
        "//Codeforces/131D",
    ],
)