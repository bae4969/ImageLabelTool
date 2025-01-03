#pragma once
#include "Macro.h"
#include "CudaType.cuh"
#include <filesystem>
#include <opencv2/core.hpp>
#include <itkImage.h>
#include <itkCudaImage.h>
#include <itkMesh.h>
#include <itkTransform.h>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/types.h>
#include <pcl/pcl_base.h>
#include <TVCommon/TVCommon.h>

namespace ImageLabelTool
{
	namespace Core
	{
#pragma region ENUM

		enum RETURN_CODE : int64_t {
			RETURN_CODE_SUCCESS = 0,
			RETURN_CODE_NOTHING_CHANGED = 1000,

			RETURN_CODE_UNEXPECTED_EXCEPTION = -1000,
			RETURN_CODE_API_INPUT = -1001,
			RETURN_CODE_FILE_IO = -1002,
			RETURN_CODE_MISMATCH_IMAGE_AND_LABEL = -1002,
			RETURN_CODE_EMPTY_RESOURCE = -1003,
		};

		enum class IMG_MODE {
			NONE,
			GRAY,
			COLOR,
			VIDEO,
		};

#pragma endregion

#pragma region TYPE

		using ImgBaseType = itk::ImageBase<2>;
		using Img8Type = itk::Image<UCHAR, 2>;
		using Img16Type = itk::Image<USHORT, 2>;
		using Img32Type = itk::Image<FLOAT, 2>;
		using Img64Type = itk::Image<double, 2>;
		using ImgRGBType = itk::Image<itk::RGBPixel<UCHAR>, 2>;
		using ImgRGBAType = itk::Image<itk::RGBAPixel<UCHAR>, 2>;
		using ImgComplexType = itk::Image<std::complex<float>, 2>;

		using VolBaseType = itk::ImageBase<3>;
		using Vol8Type = itk::Image<UCHAR, 3>;
		using Vol16Type = itk::Image<USHORT, 3>;
		using Vol32Type = itk::Image<FLOAT, 3>;
		using Vol64Type = itk::Image<double, 3>;
		using VolRGBType = itk::Image<itk::RGBPixel<UCHAR>, 3>;
		using VolRGBAType = itk::Image<itk::RGBAPixel<UCHAR>, 3>;
		using VolComplexType = itk::Image<std::complex<float>, 3>;

		using TransformType = itk::Transform<double>;

		using ImgBasePtr = ImgBaseType::Pointer;
		using Img8Ptr = Img8Type::Pointer;
		using Img16Ptr = Img16Type::Pointer;
		using Img32Ptr = Img32Type::Pointer;
		using Img64Ptr = Img64Type::Pointer;
		using ImgRGBPtr = ImgRGBType::Pointer;
		using ImgRGBAPtr = ImgRGBAType::Pointer;
		using ImgComplexPtr = ImgComplexType::Pointer;

		using VolBasePtr = VolBaseType::Pointer;
		using Vol8Ptr = Vol8Type::Pointer;
		using Vol16Ptr = Vol16Type::Pointer;
		using Vol32Ptr = Vol32Type::Pointer;
		using Vol64Ptr = Vol64Type::Pointer;
		using VolRGBPtr = VolRGBType::Pointer;
		using VolRGBAPtr = VolRGBAType::Pointer;
		using VolComplexPtr = VolComplexType::Pointer;


		using CuImg8Type = itk::CudaImage<UCHAR, 2>;
		using CuImg16Type = itk::CudaImage<USHORT, 2>;
		using CuImg32Type = itk::CudaImage<FLOAT, 2>;
		using CuImg64Type = itk::CudaImage<double, 2>;
		using CuImgRGBType = itk::CudaImage<itk::RGBPixel<UCHAR>, 2>;
		using CuImgRGBAType = itk::CudaImage<itk::RGBAPixel<UCHAR>, 2>;

		using CuVol8Type = itk::CudaImage<UCHAR, 3>;
		using CuVol16Type = itk::CudaImage<USHORT, 3>;
		using CuVol32Type = itk::CudaImage<FLOAT, 3>;
		using CuVol64Type = itk::CudaImage<double, 3>;
		using CuVolRGBType = itk::CudaImage<itk::RGBPixel<UCHAR>, 3>;
		using CuVolRGBAType = itk::CudaImage<itk::RGBAPixel<UCHAR>, 3>;


		using CuImg8Ptr = CuImg8Type::Pointer;
		using CuImg16Ptr = CuImg16Type::Pointer;
		using CuImg32Ptr = CuImg32Type::Pointer;
		using CuImg64Ptr = CuImg64Type::Pointer;
		using CuImgRGBPtr = CuImgRGBType::Pointer;
		using CuImgRGBAPtr = CuImgRGBAType::Pointer;

		using CuVol8Ptr = CuVol8Type::Pointer;
		using CuVol16Ptr = CuVol16Type::Pointer;
		using CuVol32Ptr = CuVol32Type::Pointer;
		using CuVol64Ptr = CuVol64Type::Pointer;
		using CuVolRGBPtr = CuVolRGBType::Pointer;
		using CuVolRGBAPtr = CuVolRGBAType::Pointer;


		using TransformPtr = TransformType::Pointer;

		using SIZE2 = Img8Type::SizeType;
		using SIZE3 = Vol8Type::SizeType;
		using SPACING2 = Img8Type::SpacingType;
		using SPACING3 = Vol8Type::SpacingType;
		using REGION2 = Img8Type::RegionType;
		using REGION3 = Vol8Type::RegionType;
		using INDEX2 = Img8Type::IndexType;
		using INDEX3 = Vol8Type::IndexType;
		using POINT2 = Img8Type::PointType;
		using POINT3 = Vol8Type::PointType;
		using VECTOR2 = itk::Vector<double, 2>;
		using VECTOR3 = itk::Vector<double, 3>;

		using PT2Type = pcl::PointXY;
		using PT3Type = pcl::PointXYZ;
		using PC2Type = pcl::PointCloud<PT2Type>;
		using PC3Type = pcl::PointCloud<PT3Type>;
		using PC2Ptr = PC2Type::Ptr;
		using PC3Ptr = PC3Type::Ptr;

		using IndexListType = pcl::Indices;
		using IndexListPtr = pcl::IndicesPtr;

		using Parameter = std::map<std::string, std::map<std::string, std::string>>;
		using VersionType = std::tuple<int64_t, int64_t, int64_t, int64_t>;

#pragma endregion

#pragma region FUNCTION

		std::string GetCurrentDateTime(bool isMili = true, bool isSpliter = true);
		std::string GetVersionString(const VersionType& ver);
		bool IsMatchVersion(VersionType& a, VersionType& b, size_t match = 4);
		size_t RemainMemoryBytes();
		size_t RemoveWithoutLastWrite(std::filesystem::path targetDir, size_t num_remain);

		std::tuple<IMG_MODE, VolBasePtr> LoadImageFile(std::filesystem::path filename);
		Vol8Ptr LoadLabelFile(std::filesystem::path filename);
		bool SaveItkFile(std::filesystem::path filePath, VolBasePtr vol);

		template<typename TYPE>
		cv::Mat GetCvSlice(typename TYPE::Pointer input, int64_t slice_index, int64_t cv_type);
		template<typename ImgType>
		Cuda::CudaVolume<typename ImgType::PixelType> GetCudaVolume(size_t deviceID, typename ImgType::Pointer vol);

#pragma endregion
	}
}