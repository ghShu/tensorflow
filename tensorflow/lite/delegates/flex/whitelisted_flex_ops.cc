/* Copyright 2018 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/
#include "tensorflow/lite/delegates/flex/whitelisted_flex_ops.h"

#include <set>

namespace tflite {
namespace flex {

bool IsWhitelistedFlexOp(const std::string& tensorflow_op_name) {
  static const std::set<std::string>* whitelisted_flex_ops =
      new std::set<std::string>({
          "Abort",
          "Abs",
          "Add",
          "AddN",
          "AddV2",
          "AdjustContrast",
          "AdjustContrastv2",
          "AdjustHue",
          "AdjustSaturation",
          "All",
          "Any",
          "ApplyAdadelta",
          "ApplyAdagrad",
          "ApplyAdagradV2",
          "ApplyAdagradDA",
          "ApplyAdam",
          "ApplyAdaMax",
          "ApplyAddSign",
          "ApplyCenteredRMSProp",
          "ApplyFtrl",
          "ApplyFtrlV2",
          "ApplyGradientDescent",
          "ApplyMomentum",
          "ApplyPowerSign",
          "ApplyProximalAdagrad",
          "ApplyProximalGradientDescent",
          "ApplyRMSProp",
          "ApproximateEqual",
          "_Arg",
          "ArgMax",
          "ArgMin",
          "_ArrayToList",
          "Assert",
          "Assign",
          "AssignAdd",
          "AssignSub",
          "AudioSpectrogram",
          "AvgPool",
          "AvgPool3D",
          "AvgPool3DGrad",
          "AvgPoolGrad",
          "BatchMatMul",
          "BatchMatMulV2",
          "BatchNormWithGlobalNormalization",
          "BatchNormWithGlobalNormalizationGrad",
          "BatchToSpace",
          "BatchToSpaceND",
          "BiasAdd",
          "BiasAddGrad",
          "BiasAddV1",
          "BoostedTreesBucketize",
          "Bucketize",
          "BroadcastArgs",
          "BroadcastGradientArgs",
          "BroadcastTo",
          "Cast",
          "Ceil",
          "CheckNumerics",
          "ComplexAbs",
          "Concat",
          "ConcatOffset",
          "ConcatV2",
          "Conj",
          "ConjugateTranspose",
          "Const",
          "ControlTrigger",
          "Conv2D",
          "Conv2DBackpropFilter",
          "Conv2DBackpropInput",
          "Conv3D",
          "Conv3DBackpropInputV2",
          "Cos",
          "Cosh",
          "Cumprod",
          "Cumsum",
          "CropAndResize",
          "CropAndResizeGradBoxes",
          "CropAndResizeGradImage",
          "CTCBeamSearchDecoder",
          "CTCGreedyDecoder",
          "DataFormatDimMap",
          "DataFormatVecPermute",
          "DebugGradientIdentity",
          "DebugGradientRefIdentity",
          "DecodeBase64",
          "DecodeBmp",
          "DecodeWav",
          "DeleteSessionTensor",
          "DepthToSpace",
          "DepthwiseConv2dNative",
          "Dequantize",
          "DestroyTemporaryVariable",
          "Diag",
          "Dilation2D",
          "Div",
          "DivNoNan",
          "DynamicPartition",
          "DynamicStitch",
          "Einsum",
          "Elu",
          "EluGrad",
          "Empty",
          "EncodeBase64",
          "EncodeWav",
          "EnsureShape",
          "Enter",
          "Equal",
          "Erf",
          "Exit",
          "Exp",
          "ExpandDims",
          "ExtractImagePatches",
          "FakeQuantWithMinMaxArgs",
          "FakeQuantWithMinMaxArgsGradient",
          "FakeQuantWithMinMaxVars",
          "FakeQuantWithMinMaxVarsGradient",
          "FakeQuantWithMinMaxVarsPerChannel",
          "FakeQuantWithMinMaxVarsPerChannelGradient",
          "FakeQueue",
          "FFT",
          "FFT2D",
          "FFT3D",
          "FIFOQueue",
          "FIFOQueueV2",
          "Fill",
          "Floor",
          "FloorDiv",
          "FloorMod",
          "FusedBatchNorm",
          "FusedBatchNormGrad",
          "FusedBatchNormGradV2",
          "FusedBatchNormGradV3",
          "FusedBatchNormV2",
          "FusedBatchNormV3",
          "FusedPadConv2D",
          "FusedResizeAndPadConv2D",
          "Gather",
          "GatherNd",
          "GatherV2",
          "GetSessionHandle",
          "GetSessionHandleV2",
          "GetSessionTensor",
          "Greater",
          "GreaterEqual",
          "_HostCast",
          "_HostRecv",
          "_HostSend",
          "Identity",
          "IdentityN",
          "IFFT",
          "IFFT2D",
          "IFFT3D",
          "IRFFT",
          "IRFFT2D",
          "IRFFT3D",
          "Imag",
          "ImageProjectiveTransformV2",
          "ImmutableConst",
          "InTopK",
          "InTopKV2",
          "Inv",
          "InvertPermutation",
          "InvGrad",
          "IsFinite",
          "IsNan",
          "IsVariableInitialized",
          "LeakyRelu",
          "LeakyReluGrad",
          "Less",
          "LessEqual",
          "LinSpace",
          "ListDiff",
          "_ListToArray",
          "Log",
          "LogicalAnd",
          "LogicalNot",
          "LogicalOr",
          "LogSoftmax",
          "LoopCond",
          "LRN",
          "MatMul",
          "MatrixDiag",
          "MatrixDiagV2",
          "MatrixDiagV3",
          "MatrixInverse",
          "MatrixSetDiag",
          "MatrixSetDiagV2",
          "MatrixSetDiagV3",
          "Max",
          "Maximum",
          "MaxPool",
          "MaxPool3D",
          "MaxPoolGrad",
          "MaxPoolGradGrad",
          "MaxPoolGradGradV2",
          "MaxPoolGradV2",
          "MaxPoolGradWithArgmax",
          "MaxPoolV2",
          "MaxPoolWithArgmax",
          "Mean",
          "Merge",
          "MergeV2Checkpoints",
          "Mfcc",
          "Min",
          "Minimum",
          "MirrorPad",
          "MirrorPadGrad",
          "Mul",
          "MulNoNan",
          "Multinomial",
          "Neg",
          "NextIteration",
          "NonMaxSuppression",
          "NonMaxSuppressionV2",
          "NonMaxSuppressionV3",
          "NonMaxSuppressionV4",
          "NonMaxSuppressionWithOverlaps",
          "NoOp",
          "NotEqual",
          "OneHot",
          "OnesLike",
          "Pack",
          "Pad",
          "PaddingFIFOQueue",
          "PaddingFIFOQueueV2",
          "PadV2",
          "ParallelDynamicStitch",
          "ParseExample",
          "ParseExampleV2",
          "ParseSequenceExample",
          "ParseSingleExample",
          "ParseSingleSequenceExample",
          "Placeholder",
          "PlaceholderV2",
          "PlaceholderWithDefault",
          "Pow",
          "PreventGradient",
          "Print",
          "PrintV2",
          "Prod",
          "QuantizedAdd",
          "QuantizedAvgPool",
          "QuantizedBatchNormWithGlobalNormalization",
          "QuantizedBiasAdd",
          "QuantizedConcat",
          "QuantizedConv2D",
          "QuantizedInstanceNorm",
          "QuantizedMatMul",
          "QuantizedMaxPool",
          "QuantizedMul",
          "QuantizeDownAndShrinkRange",
          "QuantizedRelu",
          "QuantizedRelu6",
          "QuantizedReshape",
          "QuantizedResizeBilinear",
          "QuantizeV2",
          "QueueClose",
          "QueueCloseV2",
          "QueueDequeue",
          "QueueDequeueMany",
          "QueueDequeueManyV2",
          "QueueDequeueUpTo",
          "QueueDequeueUpToV2",
          "QueueDequeueV2",
          "QueueEnqueue",
          "QueueEnqueueMany",
          "QueueEnqueueManyV2",
          "QueueEnqueueV2",
          "QueueIsClosed",
          "QueueIsClosedV2",
          "QueueSize",
          "QueueSizeV2",
          "RaggedRange",
          "RaggedTensorToTensor",
          "RandomGamma",
          "RandomStandardNormal",
          "RandomUniform",
          "RandomUniformInt",
          "Range",
          "Rank",
          "Real",
          "RealDiv",
          "Reciprocal",
          "ReciprocalGrad",
          "ReduceJoin",
          "_Recv",
          "RefEnter",
          "RefExit",
          "RefIdentity",
          "RefMerge",
          "RefNextIteration",
          "RefSelect",
          "RefSwitch",
          "RegexReplace",
          "Relu",
          "Relu6",
          "Relu6Grad",
          "ReluGrad",
          "RemoteCall",
          "RequantizationRange",
          "Requantize",
          "Reshape",
          "ResizeBilinear",
          "ResizeBilinearGrad",
          "ResizeNearestNeighbor",
          "ResizeNearestNeighborGrad",
          "ResourceApplyAdadelta",
          "ResourceApplyAdagrad",
          "ResourceApplyAdagradV2",
          "ResourceApplyAdagradDA",
          "ResourceApplyAdam",
          "ResourceApplyAdaMax",
          "ResourceApplyAddSign",
          "ResourceApplyCenteredRMSProp",
          "ResourceApplyFtrl",
          "ResourceApplyFtrlV2",
          "ResourceApplyGradientDescent",
          "ResourceApplyMomentum",
          "ResourceApplyPowerSign",
          "ResourceApplyProximalAdagrad",
          "ResourceApplyProximalGradientDescent",
          "ResourceApplyRMSProp",
          "ResourceSparseApplyAdadelta",
          "ResourceSparseApplyAdagrad",
          "ResourceSparseApplyAdagradDA",
          "ResourceSparseApplyCenteredRMSProp",
          "ResourceSparseApplyFtrl",
          "ResourceSparseApplyFtrlV2",
          "ResourceSparseApplyMomentum",
          "ResourceSparseApplyProximalAdagrad",
          "ResourceSparseApplyProximalGradientDescent",
          "ResourceSparseApplyRMSProp",
          "ResourceStridedSliceAssign",
          "Restore",
          "RestoreSlice",
          "RestoreV2",
          "_Retval",
          "Reverse",
          "ReverseSequence",
          "ReverseV2",
          "RFFT",
          "RFFT2D",
          "RFFT3D",
          "Round",
          "Rsqrt",
          "RsqrtGrad",
          "SampleDistortedBoundingBoxV2",
          "Save",
          "SaveSlices",
          "SaveV2",
          "ScatterNd",
          "SegmentMax",
          "SegmentMean",
          "SegmentMin",
          "SegmentProd",
          "SegmentSum",
          "Select",
          "Selu",
          "SeluGrad",
          "_Send",
          "Shape",
          "ShapeN",
          "ShardedFilename",
          "ShardedFilespec",
          "Sigmoid",
          "SigmoidGrad",
          "Sign",
          "Sin",
          "Sinh",
          "Size",
          "Slice",
          "Softmax",
          "SoftmaxCrossEntropyWithLogits",
          "Softplus",
          "SoftplusGrad",
          "Softsign",
          "SoftsignGrad",
          "SpaceToBatch",
          "SpaceToBatchND",
          "SpaceToDepth",
          "SparseApplyAdadelta",
          "SparseApplyAdagrad",
          "SparseApplyAdagradDA",
          "SparseApplyCenteredRMSProp",
          "SparseApplyFtrl",
          "SparseApplyFtrlV2",
          "SparseApplyMomentum",
          "SparseApplyProximalAdagrad",
          "SparseApplyProximalGradientDescent",
          "SparseApplyRMSProp",
          "SparseCross",
          "SparseCrossHashed",
          "SparseCrossV2",
          "SparseFillEmptyRows",
          "SparseFillEmptyRowsGrad",
          "SparseReshape",
          "SparseSegmentMean",
          "SparseSegmentMeanGrad",
          "SparseSegmentMeanWithNumSegments",
          "SparseSegmentSqrtN",
          "SparseSegmentSqrtNGrad",
          "SparseSegmentSqrtNWithNumSegments",
          "SparseSegmentSum",
          "SparseSegmentSumWithNumSegments",
          "SparseToDense",
          "Split",
          "SplitV",
          "Sqrt",
          "SqrtGrad",
          "Square",
          "SquaredDifference",
          "Squeeze",
          "Stack",
          "StackClose",
          "StackCloseV2",
          "StackPop",
          "StackPopV2",
          "StackPush",
          "StackPushV2",
          "StackV2",
          "StaticRegexReplace",
          "StopGradient",
          "StridedSlice",
          "StridedSliceAssign",
          "StridedSliceGrad",
          "StringJoin",
          "StringSplit",
          "StringSplitV2",
          "StringToHashBucket",
          "StringToHashBucketFast",
          "StringToHashBucketStrong",
          "Sub",
          "Substr",
          "Sum",
          "Switch",
          "SymbolicGradient",
          "Tan",
          "Tanh",
          "TanhGrad",
          "TemporaryVariable",
          "TensorArray",
          "TensorArrayClose",
          "TensorArrayCloseV2",
          "TensorArrayCloseV3",
          "TensorArrayConcat",
          "TensorArrayConcatV2",
          "TensorArrayConcatV3",
          "TensorArrayGather",
          "TensorArrayGatherV2",
          "TensorArrayGatherV3",
          "TensorArrayGrad",
          "TensorArrayGradV2",
          "TensorArrayGradV3",
          "TensorArrayGradWithShape",
          "TensorArrayPack",
          "TensorArrayRead",
          "TensorArrayReadV2",
          "TensorArrayReadV3",
          "TensorArrayScatter",
          "TensorArrayScatterV2",
          "TensorArrayScatterV3",
          "TensorArraySize",
          "TensorArraySizeV2",
          "TensorArraySizeV3",
          "TensorArraySplit",
          "TensorArraySplitV2",
          "TensorArraySplitV3",
          "TensorArrayUnpack",
          "TensorArrayV2",
          "TensorArrayV3",
          "TensorArrayWrite",
          "TensorArrayWriteV2",
          "TensorArrayWriteV3",
          "Tile",
          "TileGrad",
          "Timestamp",
          "TopK",
          "TopKV2",
          "Transpose",
          "TruncateDiv",
          "TruncatedNormal",
          "UnicodeDecode",
          "UnicodeDecodeWithOffsets",
          "UnicodeEncode",
          "UnicodeTranscode",
          "Unique",
          "UniqueV2",
          "UniqueWithCounts",
          "UniqueWithCountsV2",
          "Unpack",
          "UnsortedSegmentMax",
          "UnsortedSegmentMin",
          "UnsortedSegmentProd",
          "UnsortedSegmentSum",
          "Variable",
          "VariableV2",
          "Where",
          "Xdivy",
          "Xlogy",
          "ZerosLike",
      });
  return whitelisted_flex_ops->find(tensorflow_op_name) !=
         whitelisted_flex_ops->end();
  // Prevent lint error about this function being too long. This function
  // is a set of ops, and making it shorter won't help readbility.
  // NOLINTNEXTLINE
}

}  // namespace flex
}  // namespace tflite
