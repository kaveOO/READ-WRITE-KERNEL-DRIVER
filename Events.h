#pragma once

#include "ntifs.h"

PLOAD_IMAGE_NOTIFY_ROUTINE ImageLoadCallback(PUNICODE_STRING ImageName, HANDLE PID, PIMAGE_INFO ImageInfo);
