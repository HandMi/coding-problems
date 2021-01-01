cc_library(
    name = "PEP014",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "PEP014_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//ProjectEulerPlus/PEP014",
        "@gtest//:gtest_main",
    ],
)

cc_binary(
    name = "PEP014_bin",
    deps = [
        "//ProjectEulerPlus/PEP014",
    ],
)
