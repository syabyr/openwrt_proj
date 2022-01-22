#
# Copyright (C) 2015-2017 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=librtlsdr
PKG_VERSION:=0.1.0
PKG_RELEASE:=1

PKG_LICENSE_FILES:=LICENSE

PKG_MAINTAINER:=mybays <mybays@qq.com>

PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL:=git://git.osmocom.org/rtl-sdr.git
PKG_SOURCE_DATE:=2017-08-02
PKG_BUILD_DIR:=$(BUILD_DIR)/rtl-sdr-$(PKG_VERSION)
PKG_SOURCE:=rtl-sdr-$(PKG_VERSION).tar.gz
PKG_BUILD_PARALLEL:=1
PKG_SOURCE_VERSION:=HEAD
PKG_MIRROR_HASH:=b04c2f9f035c5aede43d731e5d58e4725d2f8bb4
PKG_SOURCE_SUBDIR:=rtl-sdr-$(PKG_VERSION)


PKG_INSTALL:=1
PKG_FIXUP:=autoreconf -vis&&autoconf

include $(INCLUDE_DIR)/package.mk

define Package/librtlsdr
  SECTION:=libs
  CATEGORY:=Libraries
  TITLE:=Cross-platform asychronous I/O library
  URL:=https://github.com/nfc-tools/libnfc
  DEPENDS:=+libpthread +librt +libusb-1.0
endef

define Package/librtlsdr/description
 libuv is a multi-platform support library with a focus on asynchronous I/O. It
 was primarily developed for use by Node.js, but it's also used by Luvit, Julia,
 pyuv, and others.
endef

define Build/Configure
	( cd $(PKG_BUILD_DIR); $(PKG_FIXUP) )
	( cd $(PKG_BUILD_DIR); ./configure )
	$(call Build/Configure/Default)
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/include/
	$(CP) \
		$(PKG_INSTALL_DIR)/usr/include/* \
		$(1)/usr/include/

	$(INSTALL_DIR) $(1)/usr/bin/
	$(CP) \
		$(PKG_INSTALL_DIR)/usr/bin/* \
		$(1)/usr/bin/

	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) \
		$(PKG_INSTALL_DIR)/usr/lib/librtlsdr.so* \
		$(1)/usr/lib/
	$(CP) \
		$(PKG_INSTALL_DIR)/usr/lib/librtlsdr.a \
		$(1)/usr/lib/

	$(INSTALL_DIR) $(1)/usr/lib/pkgconfig
	$(CP) \
		$(PKG_INSTALL_DIR)/usr/lib/pkgconfig/librtlsdr.pc \
		$(1)/usr/lib/pkgconfig/
endef

define Package/librtlsdr/install
	$(INSTALL_DIR) $(1)/usr/lib/
	$(CP) \
		$(PKG_INSTALL_DIR)/usr/lib/librtlsdr.so* \
		$(1)/usr/lib/

	$(INSTALL_DIR) $(1)/usr/bin/
	$(CP) \
		$(PKG_INSTALL_DIR)/usr/bin/rtl_* \
		$(1)/usr/bin/
endef

$(eval $(call BuildPackage,librtlsdr))
