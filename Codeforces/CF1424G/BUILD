cc_library(
    name = "CF1424G",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "CF1424G_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//Codeforces/CF1424G",
        "@gtest//:gtest_main",
    ],
    data = glob(["data/*.txt"]),
)

cc_binary(
    name = "CF1424G_bin",
    deps = [
        "//Codeforces/CF1424G",
    ],
)
