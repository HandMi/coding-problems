cc_library(
    name = "8B",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "8B_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//8B",
        "@gtest//:gtest_main",
    ],
)

cc_binary(
    name = "8B_exe",
    deps = [
        "//8B",
    ],
)