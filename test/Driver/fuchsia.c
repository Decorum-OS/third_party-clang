// RUN: %clang %s -### --target=x86_64-unknown-fuchsia \
// RUN:     --sysroot=%S/platform 2>&1 | FileCheck %s
// CHECK: {{.*}}clang{{.*}}" "-cc1"
// CHECK: "-fuse-init-array"
// CHECK: "-isysroot" "[[SYSROOT:[^"]+]]"
// CHECK: "-internal-externc-isystem" "[[SYSROOT]]{{/|\\\\}}include"
// CHECK: {{.*}}lld{{.*}}" "-flavor" "gnu"
// CHECK: "--sysroot=[[SYSROOT]]"
// CHECK: "-Ttext-segment=0x1000000"
// CHECK: crt1.o
// CHECK-NOT: crti.o
// CHECK-NOT: crtbegin.o
// CHECK: "-L[[SYSROOT]]/lib"
// CHECK: "{{.*[/\\]}}libclang_rt.builtins-x86_64.a"
// CHECK: "-lc"
// CHECK-NOT: crtend.o
// CHECK-NOT: crtn.o

// RUN: %clang %s -### --target=x86_64-unknown-fuchsia -rtlib=libgcc 2>&1 \
// RUN:     | FileCheck %s -check-prefix=CHECK-RTLIB
// CHECK-RTLIB: error: invalid runtime library name in argument '-rtlib=libgcc'
