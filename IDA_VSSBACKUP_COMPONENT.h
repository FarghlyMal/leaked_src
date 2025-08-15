/*
 * IDA Pro Structure Definitions for IVssBackupComponents COM Interface
 * Generated from vsbackup.h
 * 
 * Usage in IDA Pro:
 * 1. Load this file via File -> Load file -> Parse C header file
 * 2. Or manually create structures in Structures window
 * 3. Apply to vtables at appropriate addresses
 */

// Forward declarations for dependent types
struct IUnknown;
struct IVssAsync;
struct IVssWriterComponentsExt;
struct IVssExamineWriterMetadata;
struct IVssEnumObject;
struct VSS_SNAPSHOT_PROP;

// GUID structure (if not already defined)
struct GUID {
    unsigned long  Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char  Data4[8];
};

// Basic types (adjust based on your platform)
typedef struct GUID Guid;
typedef wchar_t* BSTR;
typedef wchar_t* LPCWSTR;
typedef wchar_t* VSS_PWSZ;
typedef long LONG;
typedef unsigned int UINT;
typedef int BOOL;
typedef long HRESULT;

// Enums used in the interface
enum VSS_COMPONENT_TYPE {
    VSS_CT_DATABASE = 0,
    VSS_CT_FILEGROUP = 1
};

enum VSS_BACKUP_TYPE {
    VSS_BT_UNDEFINED = 0,
    VSS_BT_FULL = 1,
    VSS_BT_INCREMENTAL = 2,
    VSS_BT_DIFFERENTIAL = 3,
    VSS_BT_LOG = 4,
    VSS_BT_COPY = 5
};

enum VSS_WRITER_STATE {
    VSS_WS_UNKNOWN = 0,
    VSS_WS_STABLE = 1,
    VSS_WS_WAITING_FOR_FREEZE = 2,
    VSS_WS_WAITING_FOR_THAW = 3,
    VSS_WS_WAITING_FOR_POST_SNAPSHOT = 4,
    VSS_WS_WAITING_FOR_BACKUP_COMPLETE = 5,
    VSS_WS_FAILED_AT_IDENTIFY = 6,
    VSS_WS_FAILED_AT_PREPARE_BACKUP = 7,
    VSS_WS_FAILED_AT_PREPARE_SNAPSHOT = 8,
    VSS_WS_FAILED_AT_FREEZE = 9,
    VSS_WS_FAILED_AT_THAW = 10,
    VSS_WS_FAILED_AT_POST_SNAPSHOT = 11,
    VSS_WS_FAILED_AT_BACKUP_COMPLETE = 12,
    VSS_WS_FAILED_AT_PRE_RESTORE = 13,
    VSS_WS_FAILED_AT_POST_RESTORE = 14
};

enum VSS_FILE_RESTORE_STATUS {
    VSS_RS_UNDEFINED = 0,
    VSS_RS_NONE = 1,
    VSS_RS_ALL = 2,
    VSS_RS_FAILED = 3
};

enum VSS_OBJECT_TYPE {
    VSS_OBJECT_UNKNOWN = 0,
    VSS_OBJECT_NONE = 1,
    VSS_OBJECT_SNAPSHOT_SET = 2,
    VSS_OBJECT_SNAPSHOT = 3,
    VSS_OBJECT_PROVIDER = 4,
    VSS_OBJECT_TYPE_COUNT = 5
};

// IUnknown vtable (base for all COM interfaces)
struct IUnknown_vtbl {
    HRESULT (__stdcall *QueryInterface)(void *this, const struct GUID *riid, void **ppvObject);
    unsigned long (__stdcall *AddRef)(void *this);
    unsigned long (__stdcall *Release)(void *this);
};

// IVssBackupComponents vtable structure
struct IVssBackupComponents_vtbl {
    // IUnknown methods
    HRESULT (__stdcall *QueryInterface)(void *this, const struct GUID *riid, void **ppvObject);
    unsigned long (__stdcall *AddRef)(void *this);
    unsigned long (__stdcall *Release)(void *this);
    
    // IVssBackupComponents methods
    HRESULT (__stdcall *GetWriterComponentsCount)(void *this, UINT *pcComponents);
    
    HRESULT (__stdcall *GetWriterComponents)(void *this, 
        UINT iWriter, 
        struct IVssWriterComponentsExt **ppWriter);
    
    HRESULT (__stdcall *InitializeForBackup)(void *this, BSTR bstrXML);
    
    HRESULT (__stdcall *SetBackupState)(void *this,
        BOOL bSelectComponents,
        BOOL bBackupBootableSystemState, 
        enum VSS_BACKUP_TYPE backupType,
        BOOL bPartialFileSupport);
    
    HRESULT (__stdcall *InitializeForRestore)(void *this, BSTR bstrXML);
    
    HRESULT (__stdcall *GatherWriterMetadata)(void *this, struct IVssAsync **pAsync);
    
    HRESULT (__stdcall *GetWriterMetadataCount)(void *this, UINT *pcWriters);
    
    HRESULT (__stdcall *GetWriterMetadata)(void *this,
        UINT iWriter,
        Guid *pidInstance,
        struct IVssExamineWriterMetadata **ppMetadata);
    
    HRESULT (__stdcall *FreeWriterMetadata)(void *this);
    
    HRESULT (__stdcall *AddComponent)(void *this,
        Guid instanceId,
        Guid writerId,
        enum VSS_COMPONENT_TYPE ct,
        LPCWSTR wszLogicalPath,
        LPCWSTR wszComponentName);
    
    HRESULT (__stdcall *PrepareForBackup)(void *this, struct IVssAsync **ppAsync);
    
    HRESULT (__stdcall *AbortBackup)(void *this);
    
    HRESULT (__stdcall *GatherWriterStatus)(void *this, struct IVssAsync **pAsync);
    
    HRESULT (__stdcall *GetWriterStatusCount)(void *this, UINT *pcWriters);
    
    HRESULT (__stdcall *FreeWriterStatus)(void *this);
    
    HRESULT (__stdcall *GetWriterStatus)(void *this,
        UINT iWriter,
        Guid *pidInstance,
        Guid *pidWriter,
        BSTR *pbstrWriter,
        enum VSS_WRITER_STATE *pnStatus,
        HRESULT *phResultFailure);
    
    HRESULT (__stdcall *SetBackupSucceeded)(void *this,
        Guid instanceId,
        Guid writerId,
        enum VSS_COMPONENT_TYPE ct,
        LPCWSTR wszLogicalPath,
        LPCWSTR wszComponentName,
        BOOL bSucceded);
    
    HRESULT (__stdcall *SetBackupOptions)(void *this,
        Guid writerId,
        enum VSS_COMPONENT_TYPE ct,
        LPCWSTR wszLogicalPath,
        LPCWSTR wszComponentName,
        LPCWSTR wszBackupOptions);
    
    HRESULT (__stdcall *SetSelectedForRestore)(void *this,
        Guid writerId,
        enum VSS_COMPONENT_TYPE ct,
        LPCWSTR wszLogicalPath,
        LPCWSTR wszComponentName,
        BOOL bSelectedForRestore);
    
    HRESULT (__stdcall *SetRestoreOptions)(void *this,
        Guid writerId,
        enum VSS_COMPONENT_TYPE ct,
        LPCWSTR wszLogicalPath,
        LPCWSTR wszComponentName,
        LPCWSTR wszRestoreOptions);
    
    HRESULT (__stdcall *SetAdditionalRestores)(void *this,
        Guid writerId,
        enum VSS_COMPONENT_TYPE ct,
        LPCWSTR wszLogicalPath,
        LPCWSTR wszComponentName,
        BOOL bAdditionalRestores);
    
    HRESULT (__stdcall *SetPreviousBackupStamp)(void *this,
        Guid writerId,
        enum VSS_COMPONENT_TYPE ct,
        LPCWSTR wszLogicalPath,
        LPCWSTR wszComponentName,
        LPCWSTR wszPreviousBackupStamp);
    
    HRESULT (__stdcall *SaveAsXML)(void *this, BSTR *pbstrXML);
    
    HRESULT (__stdcall *BackupComplete)(void *this, struct IVssAsync **ppAsync);
    
    HRESULT (__stdcall *AddAlternativeLocationMapping)(void *this,
        Guid writerId,
        enum VSS_COMPONENT_TYPE componentType,
        LPCWSTR wszLogicalPath,
        LPCWSTR wszComponentName,
        LPCWSTR wszPath,
        LPCWSTR wszFilespec,
        BOOL bRecursive,
        LPCWSTR wszDestination);
    
    HRESULT (__stdcall *AddRestoreSubcomponent)(void *this,
        Guid writerId,
        enum VSS_COMPONENT_TYPE componentType,
        LPCWSTR wszLogicalPath,
        LPCWSTR wszComponentName,
        LPCWSTR wszSubComponentLogicalPath,
        LPCWSTR wszSubComponentName,
        BOOL bRepair);
    
    HRESULT (__stdcall *SetFileRestoreStatus)(void *this,
        Guid writerId,
        enum VSS_COMPONENT_TYPE ct,
        LPCWSTR wszLogicalPath,
        LPCWSTR wszComponentName,
        enum VSS_FILE_RESTORE_STATUS status);
    
    HRESULT (__stdcall *PreRestore)(void *this, struct IVssAsync **ppAsync);
    
    HRESULT (__stdcall *PostRestore)(void *this, struct IVssAsync **ppAsync);
    
    HRESULT (__stdcall *SetContext)(void *this, LONG lContext);
    
    HRESULT (__stdcall *StartSnapshotSet)(void *this, Guid *pSnapshotSetId);
    
    HRESULT (__stdcall *AddToSnapshotSet)(void *this,
        VSS_PWSZ pwszVolumeName,
        Guid ProviderId,
        Guid *pidSnapshot);
    
    HRESULT (__stdcall *DoSnapshotSet)(void *this, struct IVssAsync **ppAsync);
    
    HRESULT (__stdcall *DeleteSnapshots)(void *this,
        Guid SourceObjectId,
        enum VSS_OBJECT_TYPE eSourceObjectType,
        BOOL bForceDelete,
        LONG *plDeletedSnapshots,
        Guid *pNondeletedSnapshotID);
    
    HRESULT (__stdcall *ImportSnapshots)(void *this, struct IVssAsync **ppAsync);
    
    HRESULT (__stdcall *RemountReadWrite)(void *this,
        Guid SnapshotId,
        struct IVssAsync **pAsync);
    
    HRESULT (__stdcall *BreakSnapshotSet)(void *this, Guid SnapshotSetId);
    
    HRESULT (__stdcall *GetSnapshotProperties)(void *this,
        Guid SnapshotId,
        struct VSS_SNAPSHOT_PROP *pProp);
    
    HRESULT (__stdcall *Query)(void *this,
        Guid QueriedObjectId,
        enum VSS_OBJECT_TYPE eQueriedObjectType,
        enum VSS_OBJECT_TYPE eReturnedObjectsType,
        struct IVssEnumObject **ppEnum);
    
    HRESULT (__stdcall *IsVolumeSupported)(void *this,
        Guid ProviderId,
        VSS_PWSZ pwszVolumeName,
        BOOL *pbSupportedByThisProvider);
    
    HRESULT (__stdcall *DisableWriterClasses)(void *this,
        const Guid *rgWriterClassId,
        UINT cClassId);
    
    HRESULT (__stdcall *EnableWriterClasses)(void *this,
        const Guid *rgWriterClassId,
        UINT cClassId);
    
    HRESULT (__stdcall *DisableWriterInstances)(void *this,
        const Guid *rgWriterInstanceId,
        UINT cInstanceId);
    
    HRESULT (__stdcall *ExposeSnapshot)(void *this,
        Guid SnapshotId,
        VSS_PWSZ wszPathFromRoot,
        LONG lAttributes,
        VSS_PWSZ wszExpose,
        VSS_PWSZ *pwszExposed);
};

// IVssBackupComponents object structure
struct IVssBackupComponents {
    struct IVssBackupComponents_vtbl *lpVtbl;
};

// Helper structure for method offsets (for IDA Pro analysis)
struct IVssBackupComponents_MethodOffsets {
    // Offset 0x00: QueryInterface
    // Offset 0x04: AddRef  
    // Offset 0x08: Release
    // Offset 0x0C: GetWriterComponentsCount
    // Offset 0x10: GetWriterComponents
    // Offset 0x14: InitializeForBackup
    // Offset 0x18: SetBackupState
    // Offset 0x1C: InitializeForRestore
    // Offset 0x20: GatherWriterMetadata
    // Offset 0x24: GetWriterMetadataCount
    // Offset 0x28: GetWriterMetadata
    // Offset 0x2C: FreeWriterMetadata
    // Offset 0x30: AddComponent
    // Offset 0x34: PrepareForBackup
    // Offset 0x38: AbortBackup
    // Offset 0x3C: GatherWriterStatus
    // Offset 0x40: GetWriterStatusCount
    // Offset 0x44: FreeWriterStatus
    // Offset 0x48: GetWriterStatus
    // Offset 0x4C: SetBackupSucceeded
    // Offset 0x50: SetBackupOptions
    // Offset 0x54: SetSelectedForRestore
    // Offset 0x58: SetRestoreOptions
    // Offset 0x5C: SetAdditionalRestores
    // Offset 0x60: SetPreviousBackupStamp
    // Offset 0x64: SaveAsXML
    // Offset 0x68: BackupComplete
    // Offset 0x6C: AddAlternativeLocationMapping
    // Offset 0x70: AddRestoreSubcomponent
    // Offset 0x74: SetFileRestoreStatus
    // Offset 0x78: PreRestore
    // Offset 0x7C: PostRestore
    // Offset 0x80: SetContext
    // Offset 0x84: StartSnapshotSet
    // Offset 0x88: AddToSnapshotSet
    // Offset 0x8C: DoSnapshotSet
    // Offset 0x90: DeleteSnapshots
    // Offset 0x94: ImportSnapshots
    // Offset 0x98: RemountReadWrite
    // Offset 0x9C: BreakSnapshotSet
    // Offset 0xA0: GetSnapshotProperties
    // Offset 0xA4: Query
    // Offset 0xA8: IsVolumeSupported
    // Offset 0xAC: DisableWriterClasses
    // Offset 0xB0: EnableWriterClasses
    // Offset 0xB4: DisableWriterInstances
    // Offset 0xB8: ExposeSnapshot
};

/*
 * Usage Notes for IDA Pro:
 * 
 * 1. Create the structures in IDA:
 *    - Go to View -> Open subviews -> Structures
 *    - Add new structure and copy the vtable definition
 * 
 * 2. Apply to COM object instances:
 *    - Find IVssBackupComponents object creation
 *    - Apply IVssBackupComponents structure to the object pointer
 *    - Apply IVssBackupComponents_vtbl to the vtable pointer
 * 
 * 3. Method analysis:
 *    - Each vtable entry is a function pointer
 *    - Use the method offsets comments to identify specific methods
 *    - Apply function signatures to improve analysis
 * 
 * 4. Common patterns to look for:
 *    - CreateVssBackupComponents() calls
 *    - QueryInterface calls with IVssBackupComponents IID
 *    - Method calls through vtable (call [eax+offset])
 */
