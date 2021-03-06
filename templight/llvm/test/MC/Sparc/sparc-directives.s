! RUN: llvm-mc %s -arch=sparc   -show-encoding | FileCheck %s --check-prefix=SPARC32
! RUN: llvm-mc %s -arch=sparcv9 -show-encoding | FileCheck %s --check-prefix=SPARC64

        ! SPARC32: .byte 24
        ! SPARC64: .byte 24
        .byte 24

        ! SPARC32: .half 1024
        ! SPARC64: .half 1024
        .half 1024

        ! SPARC32: .word 65536
        ! SPARC64: .word 65536
        .word 65536

        ! SPARC32: .word 65536
        ! SPARC64: .xword 65536
        .nword 65536

