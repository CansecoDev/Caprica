#pragma once

#include <string>

#include <common/CapricaFileLocation.h>
#include <common/CapricaReferenceState.h>

#include <papyrus/PapyrusResolutionContext.h>
#include <papyrus/PapyrusType.h>
#include <papyrus/PapyrusUserFlags.h>
#include <papyrus/PapyrusValue.h>

#include <pex/PexFile.h>
#include <pex/PexObject.h>
#include <pex/PexVariable.h>

namespace caprica { namespace papyrus {

struct PapyrusVariable final
{
  std::string name{ "" };
  PapyrusType type;
  PapyrusUserFlags userFlags{ };
  PapyrusValue defaultValue{ PapyrusValue::Default() };

  CapricaFileLocation location;
  const PapyrusObject* parent{ nullptr };
  CapricaReferenceState referenceState{ };

  bool isConst() const { return userFlags.isConst; }

  explicit PapyrusVariable(CapricaFileLocation loc, const PapyrusType& tp, const PapyrusObject* par) : location(loc), type(tp), parent(par) { }
  PapyrusVariable(const PapyrusVariable&) = delete;
  ~PapyrusVariable() = default;

  void buildPex(CapricaReportingContext& repCtx, pex::PexFile* file, pex::PexObject* obj) const;
  void semantic(PapyrusResolutionContext* ctx);
};

}}
