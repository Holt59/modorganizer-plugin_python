#include "proxypluginwrappers.h"

#include "gilock.h"
#include <QUrl>
#include <QWidget>

#include "pythonwrapperutilities.h"
#include "sipApiAccess.h"

#include <variant>
#include <tuple>

namespace boost
{
 // See bug https://connect.microsoft.com/VisualStudio/Feedback/Details/2852624
#if (_MSC_VER == 1900)
	template<> const volatile MOBase::IOrganizer* get_pointer(const volatile MOBase::IOrganizer* p) { return p; }
	template<> const volatile MOBase::IModInterface* get_pointer(const volatile MOBase::IModInterface* p) { return p; }
	template<> const volatile MOBase::IPluginGame* get_pointer(const volatile MOBase::IPluginGame* p) { return p; }
	template<> const volatile MOBase::IProfile* get_pointer(const volatile MOBase::IProfile* p) { return p; }
	template<> const volatile MOBase::IModList* get_pointer(const volatile MOBase::IModList* p) { return p; }
	template<> const volatile MOBase::IPluginList* get_pointer(const volatile MOBase::IPluginList* p) { return p; }
	template<> const volatile MOBase::IDownloadManager* get_pointer(const volatile MOBase::IDownloadManager* p) { return p; }
	template<> const volatile MOBase::IModRepositoryBridge* get_pointer(const volatile MOBase::IModRepositoryBridge* p) { return p; }
#endif
}

using namespace MOBase;


#define COMMON_I_PLUGIN_WRAPPER_DEFINITIONS(class_name) \
bool class_name::init(MOBase::IOrganizer *moInfo) \
{ \
  return basicWrapperFunctionImplementation<class_name, bool>(this, "init", boost::python::ptr(moInfo)); \
} \
 \
QString class_name::name() const \
{ \
  return basicWrapperFunctionImplementation<class_name, QString>(this, "name"); \
} \
 \
QString class_name::author() const \
{ \
  return basicWrapperFunctionImplementation<class_name, QString>(this, "author"); \
} \
 \
QString class_name::description() const \
{ \
  return basicWrapperFunctionImplementation<class_name, QString>(this, "description"); \
} \
 \
MOBase::VersionInfo class_name::version() const \
{ \
  return basicWrapperFunctionImplementation<class_name, MOBase::VersionInfo>(this, "version"); \
} \
 \
bool class_name::isActive() const \
{ \
  return basicWrapperFunctionImplementation<class_name, bool>(this, "isActive"); \
} \
 \
QList<MOBase::PluginSetting> class_name::settings() const \
{ \
  return basicWrapperFunctionImplementation<class_name, QList<MOBase::PluginSetting>>(this, "settings"); \
}

/// end COMMON_I_PLUGIN_WRAPPER_DEFINITIONS
/////////////////////////////
/// IPlugin Wrapper


COMMON_I_PLUGIN_WRAPPER_DEFINITIONS(IPluginWrapper)
/// end IPlugin Wrapper
/////////////////////////////////////
/// IPluginDiagnose Wrapper


COMMON_I_PLUGIN_WRAPPER_DEFINITIONS(IPluginDiagnoseWrapper)

std::vector<unsigned int> IPluginDiagnoseWrapper::activeProblems() const
{
  return basicWrapperFunctionImplementation<IPluginDiagnoseWrapper, std::vector<unsigned int>>(this, "activeProblems");
}

QString IPluginDiagnoseWrapper::shortDescription(unsigned int key) const
{
  return basicWrapperFunctionImplementation<IPluginDiagnoseWrapper, QString>(this, "shortDescription", key);
}

QString IPluginDiagnoseWrapper::fullDescription(unsigned int key) const
{
  return basicWrapperFunctionImplementation<IPluginDiagnoseWrapper, QString>(this, "fullDescription", key);
}

bool IPluginDiagnoseWrapper::hasGuidedFix(unsigned int key) const
{
  return basicWrapperFunctionImplementation<IPluginDiagnoseWrapper, bool>(this, "hasGuidedFix", key);
}

void IPluginDiagnoseWrapper::startGuidedFix(unsigned int key) const
{
  basicWrapperFunctionImplementation<IPluginDiagnoseWrapper, void>(this, "startGuidedFix", key);
}

/// end IPluginDiagnose Wrapper
/////////////////////////////////////
/// IPluginFileMapper Wrapper


COMMON_I_PLUGIN_WRAPPER_DEFINITIONS(IPluginFileMapperWrapper)

MappingType IPluginFileMapperWrapper::mappings() const
{
  return basicWrapperFunctionImplementation<IPluginFileMapperWrapper, MappingType>(this, "mappings");
}
/// end IPluginFileMapper Wrapper
/////////////////////////////////////
/// IPluginGame Wrapper


QString IPluginGameWrapper::gameName() const
{
  return basicWrapperFunctionImplementation<IPluginGameWrapper, QString>(this, "gameName");
}

void IPluginGameWrapper::initializeProfile(const QDir & directory, ProfileSettings settings) const
{
  basicWrapperFunctionImplementation<IPluginGameWrapper, void>(this, "initializeProfile", directory, settings);
}

QString IPluginGameWrapper::savegameExtension() const
{
  return basicWrapperFunctionImplementation<IPluginGameWrapper, QString>(this, "savegameExtension");
}

QString IPluginGameWrapper::savegameSEExtension() const
{
  return basicWrapperFunctionImplementation<IPluginGameWrapper, QString>(this, "savegameSEExtension");
}

bool IPluginGameWrapper::isInstalled() const
{
  return basicWrapperFunctionImplementation<IPluginGameWrapper, bool>(this, "isInstalled");
}

QIcon IPluginGameWrapper::gameIcon() const
{
  return basicWrapperFunctionImplementation<IPluginGameWrapper, QIcon>(this, "gameIcon");
}

QDir IPluginGameWrapper::gameDirectory() const
{
  return basicWrapperFunctionImplementation<IPluginGameWrapper, QDir>(this, "gameDirectory");
}

QDir IPluginGameWrapper::dataDirectory() const
{
  return basicWrapperFunctionImplementation<IPluginGameWrapper, QDir>(this, "dataDirectory");
}

void IPluginGameWrapper::setGamePath(const QString & path)
{
  basicWrapperFunctionImplementation<IPluginGameWrapper, void>(this, "setGamePath", path);
}

QDir IPluginGameWrapper::documentsDirectory() const
{
  return basicWrapperFunctionImplementation<IPluginGameWrapper, QDir>(this, "documentsDirectory");
}

QDir IPluginGameWrapper::savesDirectory() const
{
  return basicWrapperFunctionImplementation<IPluginGameWrapper, QDir>(this, "savesDirectory");
}

QList<MOBase::ExecutableInfo> IPluginGameWrapper::executables() const
{
  return basicWrapperFunctionImplementation<IPluginGameWrapper, QList<MOBase::ExecutableInfo>>(this, "executables");
}

QList<MOBase::ExecutableForcedLoadSetting> IPluginGameWrapper::executableForcedLoads() const
{
  return basicWrapperFunctionImplementation<IPluginGameWrapper, QList<MOBase::ExecutableForcedLoadSetting>>(this, "executableForcedLoads");
}

QString IPluginGameWrapper::steamAPPId() const
{
  return basicWrapperFunctionImplementation<IPluginGameWrapper, QString>(this, "steamAPPId");
}

QStringList IPluginGameWrapper::primaryPlugins() const
{
  return basicWrapperFunctionImplementation<IPluginGameWrapper, QStringList>(this, "primaryPlugins");
}

QStringList IPluginGameWrapper::gameVariants() const
{
  return basicWrapperFunctionImplementation<IPluginGameWrapper, QStringList>(this, "gameVariants");
}

void IPluginGameWrapper::setGameVariant(const QString & variant)
{
  basicWrapperFunctionImplementation<IPluginGameWrapper, void>(this, "setGameVariant", variant);
}

QString IPluginGameWrapper::binaryName() const
{
  return basicWrapperFunctionImplementation<IPluginGameWrapper, QString>(this, "binaryName");
}

QString IPluginGameWrapper::gameShortName() const
{
  return basicWrapperFunctionImplementation<IPluginGameWrapper, QString>(this, "gameShortName");
}

QStringList IPluginGameWrapper::primarySources() const
{
  return basicWrapperFunctionImplementation<IPluginGameWrapper, QStringList>(this, "primarySources");
}

QStringList IPluginGameWrapper::validShortNames() const
{
  return basicWrapperFunctionImplementation<IPluginGameWrapper, QStringList>(this, "validShortNames");
}

QString IPluginGameWrapper::gameNexusName() const
{
  return basicWrapperFunctionImplementation<IPluginGameWrapper, QString>(this, "gameNexusName");
}

QStringList IPluginGameWrapper::iniFiles() const
{
  return basicWrapperFunctionImplementation<IPluginGameWrapper, QStringList>(this, "iniFiles");
}

QStringList IPluginGameWrapper::DLCPlugins() const
{
  return basicWrapperFunctionImplementation<IPluginGameWrapper, QStringList>(this, "DLCPlugins");
}

QStringList IPluginGameWrapper::CCPlugins() const
{
  return basicWrapperFunctionImplementation<IPluginGameWrapper, QStringList>(this, "CCPlugins");
}

IPluginGame::LoadOrderMechanism IPluginGameWrapper::loadOrderMechanism() const
{
  return basicWrapperFunctionImplementation<IPluginGameWrapper, IPluginGame::LoadOrderMechanism>(this, "loadOrderMechanism");
}

IPluginGame::SortMechanism IPluginGameWrapper::sortMechanism() const
{
  return basicWrapperFunctionImplementation<IPluginGameWrapper, IPluginGame::SortMechanism>(this, "sortMechanism");
}

int IPluginGameWrapper::nexusModOrganizerID() const
{
  return basicWrapperFunctionImplementation<IPluginGameWrapper, int>(this, "nexusModOrganizerID");
}

int IPluginGameWrapper::nexusGameID() const
{
  return basicWrapperFunctionImplementation<IPluginGameWrapper, int>(this, "nexusGameID");
}

bool IPluginGameWrapper::looksValid(QDir const & dir) const
{
  return basicWrapperFunctionImplementation<IPluginGameWrapper, bool>(this, "looksValid", dir);
}

QString IPluginGameWrapper::gameVersion() const
{
  return basicWrapperFunctionImplementation<IPluginGameWrapper, QString>(this, "gameVersion");
}

QString IPluginGameWrapper::getLauncherName() const
{
  return basicWrapperFunctionImplementation<IPluginGameWrapper, QString>(this, "getLauncherName");
}

COMMON_I_PLUGIN_WRAPPER_DEFINITIONS(IPluginGameWrapper)

std::map<std::type_index, boost::any> IPluginGameWrapper::featureList() const
{
  return basicWrapperFunctionImplementation<IPluginGameWrapper, std::map<std::type_index, boost::any>>(this, "_featureList");
}
/// end IPluginGame Wrapper
/////////////////////////////////////
/// IPluginInstaller macro

#define COMMON_I_PLUGIN_INSTALLER_WRAPPER_DEFINITIONS(class_name) \
unsigned int class_name::priority() const { return basicWrapperFunctionImplementation<class_name, unsigned int>(this, "priority"); } \
bool class_name::isManualInstaller() const { return basicWrapperFunctionImplementation<class_name, bool>(this, "isManualInstaller"); } \
bool class_name::isArchiveSupported(std::shared_ptr<const IFileTree> tree) const { return basicWrapperFunctionImplementation<class_name, bool>(this, "isArchiveSupported", tree); } 

/// end IPluginInstaller macro
/////////////////////////////////////
/// IPluginInstaller Wrapper

COMMON_I_PLUGIN_WRAPPER_DEFINITIONS(IPluginInstallerSimpleWrapper)
COMMON_I_PLUGIN_INSTALLER_WRAPPER_DEFINITIONS(IPluginInstallerSimpleWrapper)

IPluginInstaller::EInstallResult IPluginInstallerSimpleWrapper::install(
  GuessedValue<QString>& modName, std::shared_ptr<IFileTree>& tree,
  QString& version, int& nexusID)
{
  namespace bpy = boost::python;

  using return_type = std::variant<
    IPluginInstaller::EInstallResult,
    std::shared_ptr<IFileTree>, 
    std::tuple<IPluginInstaller::EInstallResult, std::shared_ptr<IFileTree>, QString, int>> ;
  auto ret = basicWrapperFunctionImplementation<IPluginInstallerSimpleWrapper, return_type>(this, "install", boost::ref(modName), tree, version, nexusID);

  return std::visit([&](auto const& t) {
    using type = std::decay_t<decltype(t)>;
    if constexpr (std::is_same_v<type, IPluginInstaller::EInstallResult>) {
      return t;
    }
    else if constexpr (std::is_same_v<type, std::shared_ptr<IFileTree>>) {
      tree = t;
      return IPluginInstaller::RESULT_SUCCESS;
    }
    else if constexpr (std::is_same_v<type, std::tuple<IPluginInstaller::EInstallResult, std::shared_ptr<IFileTree>, QString, int>>) {
      tree = std::get<1>(t);
      version = std::get<2>(t);
      nexusID = std::get<3>(t);
      return std::get<0>(t);
    }
  }, ret);
}

/// end IPluginInstallerSimple Wrapper
/////////////////////////////////////
/// IPluginInstallerCustom Wrapper
COMMON_I_PLUGIN_WRAPPER_DEFINITIONS(IPluginInstallerCustomWrapper)
COMMON_I_PLUGIN_INSTALLER_WRAPPER_DEFINITIONS(IPluginInstallerCustomWrapper)

bool IPluginInstallerCustomWrapper::isArchiveSupported(const QString &archiveName) const
{
  return basicWrapperFunctionImplementation<IPluginInstallerCustomWrapper, bool>(this, "isArchiveSupported", archiveName);
}

std::set<QString> IPluginInstallerCustomWrapper::supportedExtensions() const
{
  return basicWrapperFunctionImplementation<IPluginInstallerCustomWrapper, std::set<QString>>(this, "supportedExtensions");
}

IPluginInstaller::EInstallResult IPluginInstallerCustomWrapper::install(
  GuessedValue<QString> &modName, QString gameName, const QString &archiveName, const QString &version, int modID)
{
  // Note: This requires far more less trouble than the "Simple" installer version since 1) there is no tree 
  // and 2) there version and modId cannot be modified:
  return basicWrapperFunctionImplementation<IPluginInstallerCustomWrapper, IPluginInstaller::EInstallResult>(
    this, "install", boost::ref(modName), gameName, archiveName, version, modID);
}

/// end IPluginInstallerCustom Wrapper
/////////////////////////////
/// IPluginModPage Wrapper


COMMON_I_PLUGIN_WRAPPER_DEFINITIONS(IPluginModPageWrapper)

QString IPluginModPageWrapper::displayName() const
{
  return basicWrapperFunctionImplementation<IPluginModPageWrapper, QString>(this, "displayName");
}

QIcon IPluginModPageWrapper::icon() const
{
  return basicWrapperFunctionImplementation<IPluginModPageWrapper, QIcon>(this, "icon");
}

QUrl IPluginModPageWrapper::pageURL() const
{
  return basicWrapperFunctionImplementation<IPluginModPageWrapper, QUrl>(this, "pageURL");
}

bool IPluginModPageWrapper::useIntegratedBrowser() const
{
  return basicWrapperFunctionImplementation<IPluginModPageWrapper, bool>(this, "useIntegratedBrowser");
}

bool IPluginModPageWrapper::handlesDownload(const QUrl & pageURL, const QUrl & downloadURL, MOBase::ModRepositoryFileInfo & fileInfo) const
{
  return basicWrapperFunctionImplementation<IPluginModPageWrapper, bool>(this, "handlesDownload", pageURL, downloadURL, fileInfo);
}

void IPluginModPageWrapper::setParentWidget(QWidget * widget)
{
  basicWrapperFunctionImplementationWithDefault<IPluginModPageWrapper, void>(this, &IPluginModPageWrapper::setParentWidget_Default, "setParentWidget", widget);
}
/// end IPluginModPage Wrapper
/////////////////////////////
/// IPluginPreview Wrapper


COMMON_I_PLUGIN_WRAPPER_DEFINITIONS(IPluginPreviewWrapper)

std::set<QString> IPluginPreviewWrapper::supportedExtensions() const
{
  return basicWrapperFunctionImplementation<IPluginPreviewWrapper, std::set<QString>>(this, "supportedExtensions");
}

QWidget *IPluginPreviewWrapper::genFilePreview(const QString &fileName, const QSize &maxSize) const
{
  // This is complicated, so we can't use the basic implementation
  try {
    GILock lock;
    boost::python::override implementation = this->get_override("genFilePreview");
    if (!implementation)
      throw pyexcept::MissingImplementation(this->className, "genFilePreview");
    boost::python::object pyVersion = implementation(fileName, maxSize);
    // We need responsibility for deleting the QWidget to be transferred to C++
    sipAPIAccess::sipAPI()->api_transfer_to(pyVersion.ptr(), Py_None);
    return boost::python::extract<QWidget *>(pyVersion)();
  }
  catch (const boost::python::error_already_set&) {
    throw pyexcept::PythonError();
  }
  catch (pyexcept::MissingImplementation const& missingImplementation) {
    throw missingImplementation;
  }
  catch (...) {
    throw pyexcept::UnknownException();
  }
}
/// end IPluginPreview Wrapper
/////////////////////////////
/// IPluginTool Wrapper


COMMON_I_PLUGIN_WRAPPER_DEFINITIONS(IPluginToolWrapper)

QString IPluginToolWrapper::displayName() const
{
  return basicWrapperFunctionImplementation<IPluginToolWrapper, QString>(this, "displayName");
}

QString IPluginToolWrapper::tooltip() const
{
  return basicWrapperFunctionImplementation<IPluginToolWrapper, QString>(this, "tooltip");
}

QIcon IPluginToolWrapper::icon() const
{
  return basicWrapperFunctionImplementation<IPluginToolWrapper, QIcon>(this, "icon");
}

void IPluginToolWrapper::setParentWidget(QWidget *parent)
{
  basicWrapperFunctionImplementationWithDefault<IPluginToolWrapper, void>(this, &IPluginToolWrapper::setParentWidget_Default, "setParentWidget", parent);
}

void IPluginToolWrapper::display() const
{
  basicWrapperFunctionImplementation<IPluginToolWrapper, void>(this, "display");
}

/// end IPluginTool Wrapper
