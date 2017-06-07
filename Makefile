TARGET = bench
C_SRCS += bench.c
C_SRCS += ed25519-donna/ed25519.c
C_SRCS += sha2.c
CFLAGS += -O2 -fno-builtin-printf -I. -Ied25519-donna

BSP_BASE = ../../bsp
include $(BSP_BASE)/env/common.mk
