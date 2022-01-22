#
# Copyright (C) 2015-2017 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=mfcuk
PKG_VERSION:=0.3.8
PKG_RELEASE:=1

PKG_LICENSE_FILES:=LICENSE

PKG_MAINTAINER:=mybays <mybays@qq.com>

PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL:=https://github.com/nfc-tools/mfcuk
PKG_SOURCE_DATE:=2017-08-02
PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_BUILD_PARALLEL:=1
PKG_SOURCE_VERSION:=HEAD
PKG_MIRROR_HASH:=9d9f01fba4ee145bc873a85898b74041ca6d8831
PKG_SOURCE_SUBDIR:=mfcuk-$(PKG_VERSION)

PKG_RELEASE:=1
PKG_FIXUP:=autoreconf -vis

include $(INCLUDE_DIR)/package.mk

define Package/mfcuk
  SECTION:=utils
  CATEGORY:=Utilities
  TITLE:=Cross-platform asychronous I/O library
  URL:=https://github.com/nfc-tools/libnfc
  DEPENDS:=+libpthread +librt +libnfc
endef

define Package/libnfc/description
 libuv is a multi-platform support library with a focus on asynchronous I/O. It
 was primarily developed for use by Node.js, but it's also used by Luvit, Julia,
 pyuv, and others.
endef


define Build/Configure
	( cd $(PKG_BUILD_DIR); $(PKG_FIXUP) )
	( cd $(PKG_BUILD_DIR); ./configure )
	$(call Build/Configure/Default)
endef


define Package/mfcuk/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/mfcuk $(1)/usr/bin/
endef

$(eval $(call BuildPackage,mfcuk))
