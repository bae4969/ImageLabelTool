#pragma once
#include "Macro.h"
#include "Type.h"

namespace ImageLabelTool
{
	namespace Core
	{
		CORE_FUNC_EXPORT int64_t Initialize(TV::LOG::CallbackLogString log_callback_func);
		CORE_FUNC_EXPORT int64_t Release();

		CORE_FUNC_EXPORT int64_t LoadData(const wchar_t* img_path, const wchar_t* lab_path);
		CORE_FUNC_EXPORT int64_t SaveData(const wchar_t* img_path, const wchar_t* lab_path);
		CORE_FUNC_EXPORT int64_t UnloadData();
		CORE_FUNC_EXPORT int64_t GetDataInfo(int64_t* type, int64_t* w, int64_t* h, int64_t* d, void** img_data_ptr, void** lab_data_ptr);
	}
}





