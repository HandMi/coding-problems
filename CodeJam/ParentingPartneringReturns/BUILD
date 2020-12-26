cc_library(
    name = "ParentingPartneringReturns",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "CJ_ParentingPartneringReturns_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//CodeJam/ParentingPartneringReturns",
        "@gtest//:gtest_main",
    ],
    data = glob(["data/*.txt"]),
)

cc_binary(
    name = "CJ_ParentingPartneringReturns_bin",
    deps = [
        "//CodeJam/ParentingPartneringReturns",
    ],
)
