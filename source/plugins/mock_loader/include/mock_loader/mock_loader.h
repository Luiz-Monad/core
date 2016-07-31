/*
 *	Loader Library by Parra Studios
 *	Copyright (C) 2016 Vicente Eduardo Ferrer Garcia <vic798@gmail.com>
 *
 *	A plugin for loading mock code at run-time into a process.
 *
 */

#ifndef MOCK_LOADER_H
#define MOCK_LOADER_H 1

#include <mock_loader/mock_loader_api.h>

#include <loader/loader_impl_interface.h>

#include <dynlink/dynlink.h>

#ifdef __cplusplus
extern "C" {
#endif

MOCK_LOADER_API loader_impl_interface mock_loader_impl_interface_singleton(void);

DYNLINK_SYMBOL_EXPORT(mock_loader_impl_interface_singleton);

MOCK_LOADER_API void mock_loader_print_info(void);

DYNLINK_SYMBOL_EXPORT(mock_loader_print_info);

#ifdef __cplusplus
}
#endif

#endif /* MOCK_LOADER_H */