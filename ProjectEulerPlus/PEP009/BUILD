cc_library(
    name = "PEP009",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "PEP009_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//ProjectEulerPlus/PEP009",
        "@gtest//:gtest_main",
    ],
)

cc_binary(
    name = "PEP009_bin",
    deps = [
        "//ProjectEulerPlus/PEP009",
    ],
)
