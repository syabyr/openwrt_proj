
include $(TOPDIR)/rules.mk

PKG_NAME:=helloworld
PKG_VERSION:=1.0
PKG_RELEASE:=1

PKG_BUILD_DIR := $(BUILD_DIR)/$(PKG_NAME)

include $(INCLUDE_DIR)/package.mk

DEPENDS:=+libc

define Package/helloworld
	SECTION:=utils
	CATEGORY:=Utilities
	TITLE:=helloworld -- prints a snarky message
	DEPENDS:=+libc
endef

define Package/helloworld/description
	If you can`t figure out what this program does,you`re proably brain-dead and need immediate medicine
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

define Package/helloworld/install
	$(INSTALL_DIR) $(1)/bin
	$(CP) /lib/x86_64-linux-gnu/libc.so.6 $(1)/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/helloworld $(1)/bin/
endef

$(eval $(call BuildPackage,helloworld))
