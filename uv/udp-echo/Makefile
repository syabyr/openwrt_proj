include $(TOPDIR)/rules.mk

PKG_NAME:=udp-echo
PKG_VERSION:=0.0.1
PKG_RELEASE:=1

PKG_LICENSE_FILES:=LICENSE

PKG_MAINTAINER:=mybays <mybays@qq.com>

PKG_BUILD_DIR := $(BUILD_DIR)/$(PKG_NAME)



include $(INCLUDE_DIR)/package.mk

define Package/udp-echo
	SECTION:=utils
	CATEGORY:=Utilities
	TITLE:=udp server -- prints a snarky message
	DEPENDS:=+libuv
endef

define Package/udp-echo/description
If you can't figure out what this program does,
you're probably brain-dead and need immediate
medical attention.
endef


define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef


define Package/udp-echo/install
	$(INSTALL_DIR) $(1)/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/udp-echo $(1)/bin/
endef

$(eval $(call BuildPackage,udp-echo))
