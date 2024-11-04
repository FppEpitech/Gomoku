pub const packages = struct {
    pub const @"1220232ab38d0c2cfb10680115c17ad2fa1a8531dbaf8bbfb359ec67e80c7d5f5758" = struct {
        pub const build_root = "/home/tjerome-rocher/.cache/zig/p/1220232ab38d0c2cfb10680115c17ad2fa1a8531dbaf8bbfb359ec67e80c7d5f5758";
        pub const build_zig = @import("1220232ab38d0c2cfb10680115c17ad2fa1a8531dbaf8bbfb359ec67e80c7d5f5758");
        pub const deps: []const struct { []const u8, []const u8 } = &.{};
    };
    pub const @"12204ee130dbefc6f0de0c2b9e48f946ae8114f5f111256724122e17575a1ee7e2fb" = struct {
        pub const build_root = "/home/tjerome-rocher/.cache/zig/p/12204ee130dbefc6f0de0c2b9e48f946ae8114f5f111256724122e17575a1ee7e2fb";
        pub const build_zig = @import("12204ee130dbefc6f0de0c2b9e48f946ae8114f5f111256724122e17575a1ee7e2fb");
        pub const deps: []const struct { []const u8, []const u8 } = &.{
        };
    };
    pub const @"12206f5d1e5bd4793fe952bbae891b7424a19026e0d296a1381074c7d21d5d76c1a1" = struct {
        pub const build_root = "/home/tjerome-rocher/.cache/zig/p/12206f5d1e5bd4793fe952bbae891b7424a19026e0d296a1381074c7d21d5d76c1a1";
        pub const build_zig = @import("12206f5d1e5bd4793fe952bbae891b7424a19026e0d296a1381074c7d21d5d76c1a1");
        pub const deps: []const struct { []const u8, []const u8 } = &.{
        };
    };
    pub const @"12208c1f2c5f730c4c03aabeb0632ade7e21914af03e6510311b449458198d0835d6" = struct {
        pub const build_root = "/home/tjerome-rocher/.cache/zig/p/12208c1f2c5f730c4c03aabeb0632ade7e21914af03e6510311b449458198d0835d6";
        pub const build_zig = @import("12208c1f2c5f730c4c03aabeb0632ade7e21914af03e6510311b449458198d0835d6");
        pub const deps: []const struct { []const u8, []const u8 } = &.{
            .{ "metrics", "1220232ab38d0c2cfb10680115c17ad2fa1a8531dbaf8bbfb359ec67e80c7d5f5758" },
            .{ "websocket", "12204ee130dbefc6f0de0c2b9e48f946ae8114f5f111256724122e17575a1ee7e2fb" },
        };
    };
    pub const @"1220b0979ea9891fa4aeb85748fc42bc4b24039d9c99a4d65d893fb1c83e921efad8" = struct {
        pub const build_root = "/home/tjerome-rocher/.cache/zig/p/1220b0979ea9891fa4aeb85748fc42bc4b24039d9c99a4d65d893fb1c83e921efad8";
        pub const build_zig = @import("1220b0979ea9891fa4aeb85748fc42bc4b24039d9c99a4d65d893fb1c83e921efad8");
        pub const deps: []const struct { []const u8, []const u8 } = &.{};
    };
    pub const @"1220c032d828e768348b321a79523812be1c4cb27e1eb7ff5df54b573fa131afd448" = struct {
        pub const build_root = "/home/tjerome-rocher/.cache/zig/p/1220c032d828e768348b321a79523812be1c4cb27e1eb7ff5df54b573fa131afd448";
        pub const build_zig = @import("1220c032d828e768348b321a79523812be1c4cb27e1eb7ff5df54b573fa131afd448");
        pub const deps: []const struct { []const u8, []const u8 } = &.{
            .{ "metrics", "1220232ab38d0c2cfb10680115c17ad2fa1a8531dbaf8bbfb359ec67e80c7d5f5758" },
        };
    };
};

pub const root_deps: []const struct { []const u8, []const u8 } = &.{
    .{ "ini", "1220b0979ea9891fa4aeb85748fc42bc4b24039d9c99a4d65d893fb1c83e921efad8" },
    .{ "logz", "1220c032d828e768348b321a79523812be1c4cb27e1eb7ff5df54b573fa131afd448" },
    .{ "zul", "12206f5d1e5bd4793fe952bbae891b7424a19026e0d296a1381074c7d21d5d76c1a1" },
    .{ "httpz", "12208c1f2c5f730c4c03aabeb0632ade7e21914af03e6510311b449458198d0835d6" },
};
