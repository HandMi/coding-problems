cc_library(
    name = "PEP016",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "PEP016_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//ProjectEulerPlus/PEP016",
        "@gtest//:gtest_main",
    ],
)

cc_binary(
    name = "PEP016_bin",
    deps = [
        "//ProjectEulerPlus/PEP016",
    ],
)
