ifeq ($(BUILD_MODE), release)
    CFLAGS      += -O3 -g
endif

ifeq ($(BUILD_MODE), debug)
    CFLAGS      += -O0 -g3 -DDEBUG=1
    CFLAGS      += -fsanitize=address -fno-omit-frame-pointer
    LDFLAGS     += -fsanitize=address
endif

ifeq ($(BUILD_MODE), events)
    CFLAGS      += -O3 -g -DDEBUG=1
endif

ifeq ($(BUILD_MODE), profile)
    CFLAGS      += -O0 -g3 -pg
    LDFLAGS     += -pg
endif

ifeq ($(filter debug profile,$(BUILD_MODE)),)
    CFLAGS		 += -DENABLE_CUSTOM_INLINING=1 -flto
endif

debug:
	@$(MAKE) re BUILD_MODE=debug

d:
	@$(MAKE) r BUILD_MODE=events

.PHONY: d debug
