#pragma once

#include <common/CapricaConfig.h>
#include <common/CapricaReportingContext.h>

namespace caprica {

struct EngineLimits final
{
  enum class Type {
    ArrayLength,
    PexFile_UserFlagCount,
    PexFunction_ParameterCount,
    PexObject_EmptyStateFunctionCount,
    PexObject_InitialValueCount,
    PexObject_NamedStateCount,
    PexObject_PropertyCount,
    PexObject_StaticFunctionCount,
    PexObject_VariableCount,
    PexState_FunctionCount,
  };

  static void checkLimit(CapricaReportingContext& repCtx, CapricaFileLocation location, Type tp, size_t value, const char* referenceName = nullptr) {
    const auto exceedsLimit = [](size_t value, size_t max) {
      return max != 0 && value > max;
    };

    switch (tp) {
      case Type::ArrayLength:
        if (exceedsLimit(value, CapricaConfig::EngineLimits::maxArrayLength))
          repCtx.warning_W2001_EngineLimits_ArrayLength(location, value, CapricaConfig::EngineLimits::maxArrayLength);
        break;
      case Type::PexFile_UserFlagCount:
        if (exceedsLimit(value, CapricaConfig::EngineLimits::maxUserFlags))
          repCtx.warning_W2002_EngineLimits_PexFile_UserFlagCount(location, value, CapricaConfig::EngineLimits::maxUserFlags);
        break;
      case Type::PexFunction_ParameterCount:
        if (exceedsLimit(value, CapricaConfig::EngineLimits::maxParametersPerFunction))
          repCtx.warning_W2003_EngineLimits_PexFunction_ParameterCount(location, value, referenceName, CapricaConfig::EngineLimits::maxParametersPerFunction);
        break;
      case Type::PexObject_EmptyStateFunctionCount:
        if (exceedsLimit(value, CapricaConfig::EngineLimits::maxFunctionsInEmptyStatePerObject))
          repCtx.warning_W2004_EngineLimits_PexObject_EmptyStateFunctionCount(location, value, CapricaConfig::EngineLimits::maxFunctionsInEmptyStatePerObject);
        break;
      case Type::PexObject_InitialValueCount:
        if (exceedsLimit(value, CapricaConfig::EngineLimits::maxInitialValuesPerObject))
          repCtx.warning_W2005_EngineLimits_PexObject_InitialValueCount(location, value, CapricaConfig::EngineLimits::maxInitialValuesPerObject);
        break;
      case Type::PexObject_NamedStateCount:
        if (exceedsLimit(value, CapricaConfig::EngineLimits::maxNamedStatesPerObject))
          repCtx.warning_W2006_EngineLimits_PexObject_NamedStateCount(location, value, CapricaConfig::EngineLimits::maxNamedStatesPerObject);
        break;
      case Type::PexObject_PropertyCount:
        if (exceedsLimit(value, CapricaConfig::EngineLimits::maxPropertiesPerObject))
          repCtx.warning_W2007_EngineLimits_PexObject_PropertyCount(location, value, CapricaConfig::EngineLimits::maxVariablesPerObject);
        break;
      case Type::PexObject_StaticFunctionCount:
        if (exceedsLimit(value, CapricaConfig::EngineLimits::maxStaticFunctionsPerObject))
          repCtx.warning_W2008_EngineLimits_PexObject_StaticFunctionCount(location, value, CapricaConfig::EngineLimits::maxStaticFunctionsPerObject);
        break;
      case Type::PexObject_VariableCount:
        if (exceedsLimit(value, CapricaConfig::EngineLimits::maxVariablesPerObject))
          repCtx.warning_W2009_EngineLimits_PexObject_VariableCount(location, value, CapricaConfig::EngineLimits::maxVariablesPerObject);
        break;
      case Type::PexState_FunctionCount:
        if (exceedsLimit(value, CapricaConfig::EngineLimits::maxFunctionsPerState))
          repCtx.warning_W2010_EngineLimits_PexState_FunctionCount(location, value, referenceName, CapricaConfig::EngineLimits::maxFunctionsPerState);
        break;
    }
  }
};

}
