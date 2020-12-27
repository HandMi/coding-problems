cc_library(
    name = "CF1327B",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "CF1327B_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//Codeforces/CF1327B",
        "@gtest//:gtest_main",
    ],
    data = glob(["data/*.txt"]),
)

cc_binary(
    name = "CF1327B_bin",
    deps = [
        "//Codeforces/CF1327B",
    ],
)
