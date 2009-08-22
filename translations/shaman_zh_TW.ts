<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.0" language="zh_TW">
<context>
    <name>AlpmHandler</name>
    <message>
        <source>: requires </source>
        <translation>: 需要 </translation>
    </message>
    <message>
        <source>: conflicts with </source>
        <translation>: 衝突 </translation>
    </message>
    <message>
        <source>%1 exists in both &apos;%2&apos; and &apos;%3&apos;</source>
        <translation>&apos;%2&apos; 和 &apos;%3&apos; 已經有 %1</translation>
    </message>
    <message>
        <source>: %1 exists in filesystem</source>
        <translation>: %1 系統上已有</translation>
    </message>
    <message>
        <source>Alpm did not give further details.</source>
        <translation>Alpm 沒有取得不確定的細節。</translation>
    </message>
</context>
<context>
    <name>BuildingDialog</name>
    <message>
        <source>Error</source>
        <translation>錯誤</translation>
    </message>
    <message>
        <source>Would you like to abort building?.
All Process will be lost.</source>
        <translation>你確定要中止建立？.
整個處理過程將會遺失。</translation>
    </message>
    <message>
        <source>&lt;br&gt;&lt;br&gt;&lt;b&gt;Building Process Aborted by the User. Building Failed.&lt;/b&gt;</source>
        <translation>&lt;br&gt;&lt;br&gt;&lt;b&gt;已被使用者中止編譯過程。 編譯失敗。&lt;/b&gt;</translation>
    </message>
    <message>
        <source>Updating ABS Tree...</source>
        <translation>更新 ABS 目錄...</translation>
    </message>
    <message>
        <source>&lt;b&gt;Starting ABS Tree Update...&lt;/b&gt;&lt;br&gt;&lt;br&gt;</source>
        <translation>&lt;b&gt;正開始 ABS 目錄更新...&lt;/b&gt;&lt;br&gt;&lt;br&gt;</translation>
    </message>
    <message>
        <source>&lt;br&gt;&lt;br&gt;&lt;b&gt;ABS Tree Was Successfully Updated!&lt;/b&gt;</source>
        <translation>&lt;br&gt;&lt;br&gt;&lt;b&gt;ABS 目錄已成功更新！&lt;/b&gt;</translation>
    </message>
    <message>
        <source>ABS Update</source>
        <translation>ABS 更新</translation>
    </message>
    <message>
        <source>Your ABS Tree was updated!</source>
        <translation>你的 ABS 目錄已經是最新的!</translation>
    </message>
    <message>
        <source>&lt;b&gt;Building %1 failed!!&lt;/b&gt;&lt;br&gt;&lt;br&gt;</source>
        <translation>&lt;b&gt;編譯 %1 失敗!!&lt;/b&gt;&lt;br&gt;&lt;br&gt;</translation>
    </message>
    <message>
        <source>&lt;b&gt;%1 was built successfully!!&lt;/b&gt;&lt;br&gt;&lt;br&gt;</source>
        <translation>&lt;b&gt;%1 已成功編譯!!&lt;/b&gt;&lt;br&gt;&lt;br&gt;</translation>
    </message>
    <message>
        <source>Processing Package %1 of %2...</source>
        <translation>正在處理套件 %2 之 %1...</translation>
    </message>
    <message>
        <source>Building %1...</source>
        <translation>正在編譯 %1...</translation>
    </message>
    <message>
        <source>&lt;b&gt;Building %1...&lt;/b&gt;&lt;br&gt;&lt;br&gt;</source>
        <translation>&lt;b&gt;正在編譯 %1...&lt;/b&gt;&lt;br&gt;&lt;br&gt;</translation>
    </message>
    <message>
        <source>&lt;b&gt;Building operation has started.&lt;/b&gt;&lt;br&gt;&lt;br&gt;</source>
        <translation>&lt;b&gt;編譯操作已經開始。&lt;/b&gt;&lt;br&gt;&lt;br&gt;</translation>
    </message>
    <message>
        <source>&lt;b&gt;Could not set up the environment correctly for %1!!&lt;/b&gt;&lt;br&gt;&lt;br&gt;</source>
        <translation>&lt;b&gt;無法正確設定 %1 的環境!!&lt;/b&gt;&lt;br&gt;&lt;br&gt;</translation>
    </message>
    <message>
        <source>Could not update the ABS Tree!</source>
        <translation>無法更新此 ABS 目錄!</translation>
    </message>
</context>
<context>
    <name>BuildingHandler</name>
    <message>
        <source>You need to have ABS installed to use Shaman&apos;s
building feature. Do you want to install it now?</source>
        <translation>你必須已經安裝 ABS 才可以使用 Shaman 的
編譯功能。你要立刻安裝 ABS 嗎?</translation>
    </message>
    <message>
        <source>Error</source>
        <translation>錯誤</translation>
    </message>
    <message>
        <source>You can not remove packages when processing
your queue from Source</source>
        <translation>正在從原始碼處理佇列時無法移除套件</translation>
    </message>
    <message>
        <source>Some of your packages do not belong to Arch
Linux&apos;s official repository. Shaman is able to
build packages from official sources only.</source>
        <translation>你的某些套件不屬於 ArchLinux
的官方套件庫。Shaman 只能夠
從官方提供的原始碼編譯套件。</translation>
    </message>
    <message>
        <source>You are about to install &lt;b&gt;%1 package&lt;/b&gt; from source. Building from source&lt;br&gt;can give some advantages, however is very slow.&lt;br&gt;If you are not sure about that, you would probably prefer to process&lt;br&gt;your queue from binary files. Before you continue, you are advised to&lt;br&gt;review your configuration to improve your building performance.</source>
        <translation>你即將要從原始碼安裝 &lt;b&gt;%1 套件&lt;/b&gt;。 從原始碼編譯&lt;br&gt;雖然很慢但會有一些優點。&lt;br&gt;如果您不知道這一點，你可能會寧可&lt;br&gt;從二進位檔案處理你的佇列。建議你繼續進行前&lt;br&gt;檢查你的設定以提高編譯性能。</translation>
    </message>
    <message>
        <source>You are about to install &lt;b&gt;%1 packages&lt;/b&gt; from source. Building from source&lt;br&gt;can give some advantages, however is very slow.&lt;br&gt;If you are not sure about that, you would probably prefer to process&lt;br&gt;your queue from binary files. Before you continue, you are advised to&lt;br&gt;review your configuration to improve your building performance.</source>
        <translation>你即將要從原始碼安裝 &lt;b&gt;%1 套件&lt;/b&gt;。 從原始碼編譯&lt;br&gt;雖然很慢但會有一些優點。&lt;br&gt;如果您不知道這一點，你可能會寧可&lt;br&gt;從二進位檔案處理你的佇列。建議你繼續進行前&lt;br&gt;檢查你的設定以提高編譯性能。</translation>
    </message>
    <message>
        <source>To be Installed</source>
        <translation>將會安裝</translation>
    </message>
    <message>
        <source>To be Upgraded</source>
        <translation>將會升級</translation>
    </message>
    <message>
        <source>Package Building</source>
        <translation>套件編譯</translation>
    </message>
    <message>
        <source>Your Packages failed to build!</source>
        <translation>你的套件編譯失敗!</translation>
    </message>
    <message>
        <source>Your packages Failed to Build.
Look at the output for more details.</source>
        <translation>你的套件編譯失敗。
查看輸出訊息了解更多細節。</translation>
    </message>
    <message>
        <source>Close</source>
        <translation>關閉</translation>
    </message>
    <message>
        <source>Building Packages Failed!!</source>
        <translation>編譯套件失敗!!</translation>
    </message>
    <message>
        <source>Shaman - Idle</source>
        <translation>Shaman - 閒置</translation>
    </message>
    <message>
        <source>Some packages failed to build.
Do you want to proceed anyway?</source>
        <translation>某些套件編譯失敗。
即使如此你仍要繼續進行嗎?</translation>
    </message>
    <message>
        <source>Install Built Packages</source>
        <translation>安裝編譯好的套件</translation>
    </message>
    <message>
        <source>Close Without Installing</source>
        <translation>不安裝就關閉</translation>
    </message>
    <message>
        <source>Packages Built Successfully!</source>
        <translation>套件編譯成功!</translation>
    </message>
    <message>
        <source>Your Packages have been built successfully, and are ready to be installed</source>
        <translation>你的套件已經成功編譯完成，且準備好可以進行安裝</translation>
    </message>
    <message>
        <source>Shaman - Processing</source>
        <translation>Shaman - 處理中</translation>
    </message>
    <message>
        <source>You are about to install &lt;b&gt;%n package(s)&lt;/b&gt; from source. Building from source&lt;br&gt;can give some advantages, however is very slow.&lt;br&gt;If you are not sure about that, you would probably prefer to process&lt;br&gt;your queue from binary files. Before you continue, you are advised to&lt;br&gt;review your configuration to improve your building performance.</source>
        <translation>你即將要從原始碼安裝 &lt;b&gt;%n 套件&lt;/b&gt;。 從原始碼編譯&lt;br&gt;雖然很慢但會有一些優點。&lt;br&gt;如果您不知道這一點，你可能會寧可&lt;br&gt;從二進位檔案處理你的佇列。建議你繼續進行前&lt;br&gt;檢查你的設定以提高編譯性能。</translation>
    </message>
</context>
<context>
    <name>CallBacks</name>
    <message>
        <source>%1 requires installing %2 from IgnorePkg/IgnoreGroup.
 Install anyway?</source>
        <translation>%1 需要從忽略的套件/群組中安裝 %2。
 即使如此也要安裝嗎?</translation>
    </message>
    <message>
        <source>%1 is in IgnorePkg/IgnoreGroup.
 Install anyway?</source>
        <translation>%1 在忽略的套件/群組的名單上。
 即使如此也要安裝嗎?</translation>
    </message>
    <message>
        <source>%1 is designated as a HoldPkg.
 Remove anyway?</source>
        <translation>%1 已被標記為保留套件。
 即使如此也要移除嗎?</translation>
    </message>
    <message>
        <source>Replace %1 with %2/%3?</source>
        <translation>以 %2/%3 取代 %1 嗎?</translation>
    </message>
    <message>
        <source>%1 conflicts with %2.
Remove %3?</source>
        <translation>%1 與 %2 衝突。
要移除 %3?</translation>
    </message>
    <message>
        <source>%1-%2: local version is newer.
Upgrade anyway?</source>
        <translation>%1-%2: 本地版本比較新。
即使如此也要更新嗎?</translation>
    </message>
    <message>
        <source>File %s is corrupted.
Do you want to delete it?</source>
        <translation>檔案 %s 已經損壞。
你要刪除它嗎?</translation>
    </message>
    <message>
        <source>File %1 is corrupted.
Do you want to delete it?</source>
        <translation>檔案 %1 已經損壞。
你要刪除它嗎?</translation>
    </message>
</context>
<context>
    <name>ConfigDialog</name>
    <message>
        <source>Shaman - Configuration</source>
        <translation>Shaman - 設定</translation>
    </message>
    <message>
        <source>Favourite Actions</source>
        <translation>常用動作</translation>
    </message>
    <message>
        <source>When Upgrading System:</source>
        <translation>當系統可升級時:</translation>
    </message>
    <message>
        <source>Upgrade Immediately</source>
        <translation>立刻升級</translation>
    </message>
    <message>
        <source>Add Upgradeable Packages To Queue</source>
        <translation>可升級套件加入到佇列</translation>
    </message>
    <message>
        <source>Ask</source>
        <translation>詢問</translation>
    </message>
    <message>
        <source>When Processing Queue</source>
        <translation>當正在處理佇列時</translation>
    </message>
    <message>
        <source>Keep application running in System Tray only</source>
        <translation>讓程式保持執行在收藏匣中</translation>
    </message>
    <message>
        <source>GUI Startup</source>
        <translation>GUI 啟動</translation>
    </message>
    <message>
        <source>Start in the System Tray</source>
        <translation>啟動於收藏匣中</translation>
    </message>
    <message>
        <source>When Application is in System Tray only</source>
        <translation>只有程式於收藏匣時</translation>
    </message>
    <message>
        <source>Update Database every</source>
        <translation>每隔多久更新資料庫</translation>
    </message>
    <message>
        <source>minutes</source>
        <comment>As in &quot;minutes&quot;</comment>
        <translation>分鐘</translation>
    </message>
    <message>
        <source>If upgrades are available:</source>
        <translation>如果可升級:</translation>
    </message>
    <message>
        <source>Just Notify</source>
        <translation>僅通知</translation>
    </message>
    <message>
        <source>Notify and add them to Queue</source>
        <translation>通知並加入到佇列</translation>
    </message>
    <message>
        <source>Maintenance</source>
        <translation>維護</translation>
    </message>
    <message>
        <source>Checkable Options</source>
        <translation>可勾選的選項</translation>
    </message>
    <message>
        <source>Use Active FTP</source>
        <translation>使用主動 FTP</translation>
    </message>
    <message>
        <source>Use Deltas (needs xdelta to be installed)</source>
        <translation>使用修補 (需要已經安裝 xdelta)</translation>
    </message>
    <message>
        <source>Advanced Options</source>
        <translation>進階選項</translation>
    </message>
    <message>
        <source>HoldPkgs:</source>
        <translation>保留套件:</translation>
    </message>
    <message>
        <source>IgnorePkgs:</source>
        <translation>忽略套件:</translation>
    </message>
    <message>
        <source>IgnoreGroups:</source>
        <translation>忽略群組:</translation>
    </message>
    <message>
        <source>NoUpgrade:</source>
        <translation>不升級:</translation>
    </message>
    <message>
        <source>NoExtract:</source>
        <translation>不解開:</translation>
    </message>
    <message>
        <source>XFerCommand: (example: /path/to/command %u) Blank for Default</source>
        <translation>XFer指令: (例如: /路徑/指令 %u) 預設為空白</translation>
    </message>
    <message>
        <source>Arch Linux Official Repositories</source>
        <translation>Arch Linux 官方套件庫</translation>
    </message>
    <message>
        <source>Here you can choose what repositories to use between Arch Linux&apos;s official ones.
Please note that packages from Unstable and Testing may break your system.</source>
        <translation>你可在這裡選擇要使用哪些 Arch Linux 的官方套件庫。
請注意 Unstable 和 Testing 的套件可能會破壞你的系統。</translation>
    </message>
    <message>
        <source>Server</source>
        <translation>伺服器</translation>
    </message>
    <message>
        <source>Mirror:</source>
        <translation>鏡像:</translation>
    </message>
    <message>
        <source>Add Mirror</source>
        <translation>加入鏡像</translation>
    </message>
    <message>
        <source>KDEMod Repositories</source>
        <translation>KDEMod 套件庫</translation>
    </message>
    <message>
        <source>KDEMod is an improved version of KDE, an Arch Linux exclusive. Featuring an 
improved Qt build, compatible with Arch Linux standard Qt&apos;s, an improved theme,
and lots of addons, KDEMod is the best way to taste the ease and the power
of KDE with the simplicity and the power of Arch.</source>
        <translation>KDEMod 是 KDE 的改良版本，Arch Linux 專用。特色有改良的 Qt 編譯、
與 Arch Linux 的標準 Qt 相容、改良的主題和許多附加元件，KDEMod 是
品嘗 KDE 的舒適強大以及 Arch 簡潔強悍的最好選擇。</translation>
    </message>
    <message>
        <source>KDEMod 3 Repository</source>
        <translation>KDEMod 3 套件庫</translation>
    </message>
    <message>
        <source>KDEMod 4 Repository (Unstable, testers only)</source>
        <translation>KDEMod 4 套件庫 (Unstable，僅供測試人員使用!)</translation>
    </message>
    <message>
        <source>Third-Party Repositories</source>
        <translation>第三方套件庫</translation>
    </message>
    <message>
        <source>You can extend your packages choice by adding other repositories. Third-Party 
Repositories act just as normal ones, and will be accessible through both Shaman
and Pacman.</source>
        <translation>你可以加入其他的套件庫來擴增套件選擇種類。第三方套件庫可作為一般套件
庫，而且不論 Shaman 或 Pacman 都可使用。</translation>
    </message>
    <message>
        <source>Repository</source>
        <translation>套件庫</translation>
    </message>
    <message>
        <source>Add New Repository</source>
        <translation>新增套件庫</translation>
    </message>
    <message>
        <source>Edit Repository</source>
        <translation>編輯套件庫</translation>
    </message>
    <message>
        <source>Remove Repository</source>
        <translation>移除套件庫</translation>
    </message>
    <message>
        <source>Preferences</source>
        <translation>偏好設定</translation>
    </message>
    <message>
        <source>Process all dependencies and queue from source first (recommended)</source>
        <translation>先從二進位檔處理全部相依性和佇列 (建議)</translation>
    </message>
    <message>
        <source>Review Building output before installing</source>
        <translation>安裝前重新檢視編譯輸出</translation>
    </message>
    <message>
        <source>ABS Configuration</source>
        <translation>ABS 設定</translation>
    </message>
    <message>
        <source>Use supfiles that match your current repositories</source>
        <translation>使用升級檔讓目前的套件庫與其相符</translation>
    </message>
    <message>
        <source>Define supfiles manually</source>
        <translation>定義手動升級檔</translation>
    </message>
    <message>
        <source>Makepkg Configuration</source>
        <translation>Makepkg 設定</translation>
    </message>
    <message>
        <source>CFlags</source>
        <translation>CFlags</translation>
    </message>
    <message>
        <source>CXXFlags</source>
        <translation>CXXFlags</translation>
    </message>
    <message>
        <source>BuildEnv</source>
        <translation>編譯環境</translation>
    </message>
    <message>
        <source>Options</source>
        <translation>選項</translation>
    </message>
    <message>
        <source>Doc_Dirs</source>
        <translation>文件資料夾</translation>
    </message>
    <message>
        <source>Build Environment</source>
        <translation>編譯環境</translation>
    </message>
    <message>
        <source>Building Path</source>
        <translation>編譯路徑</translation>
    </message>
    <message>
        <source>Remove installed makedepends after build</source>
        <translation>編譯完成後移除編譯相依套件</translation>
    </message>
    <message>
        <source>Clean Build Environment after installation</source>
        <translation>安裝完成後清除編譯環境</translation>
    </message>
    <message>
        <source>General</source>
        <translation>一般</translation>
    </message>
    <message>
        <source>Clean Unused Databases</source>
        <translation>清除未用過的資料庫</translation>
    </message>
    <message>
        <source>Clean Cache</source>
        <translation>清除快取</translation>
    </message>
    <message>
        <source>Empty Cache</source>
        <translation>空的快取</translation>
    </message>
    <message>
        <source>Optimize Pacman Database</source>
        <translation>最佳化 Pacman 資料庫</translation>
    </message>
    <message>
        <source>Clean All Building Environments</source>
        <translation>清除所有編譯環境</translation>
    </message>
    <message>
        <source>Repositories</source>
        <translation>套件庫</translation>
    </message>
    <message>
        <source>Pacman</source>
        <translation>Pacman</translation>
    </message>
    <message>
        <source>ABS</source>
        <translation>ABS</translation>
    </message>
    <message>
        <source>Enter Here the Repository&apos;s Name</source>
        <translation>這裡輸入套件庫的名稱</translation>
    </message>
    <message>
        <source>Enter Here the Repository&apos;s Server</source>
        <translation>這裡輸入套件庫的伺服器</translation>
    </message>
    <message>
        <source>Cleaning up unused Databases...</source>
        <translation>正在清理未用過的資料庫...</translation>
    </message>
    <message>
        <source>Cleaning up Cache...</source>
        <translation>正在清理快取...</translation>
    </message>
    <message>
        <source>Deleting Cache...</source>
        <translation>正在刪除快取...</translation>
    </message>
    <message>
        <source>Cleaning up building Environments...</source>
        <translation>正在清理編譯環境...</translation>
    </message>
    <message>
        <source>Cleaning up Unused Databases Failed!</source>
        <translation>清理未用過的資料庫失敗!</translation>
    </message>
    <message>
        <source>Cleaning up Cache Failed!</source>
        <translation>清理快取失敗!</translation>
    </message>
    <message>
        <source>Deleting Cache Failed!</source>
        <translation>刪除快取失敗!</translation>
    </message>
    <message>
        <source>Could not clean Build Environments!!</source>
        <translation>無法清除編譯環境!!</translation>
    </message>
    <message>
        <source>Unused Databases Cleaned up successfully!</source>
        <translation>未用過的資料庫清理成功!</translation>
    </message>
    <message>
        <source>Cache Cleaned Up Successfully!</source>
        <translation>快取清理成功!</translation>
    </message>
    <message>
        <source>Cache Successfully Deleted!</source>
        <translation>快取已成功刪除!</translation>
    </message>
    <message>
        <source>Build Environments Successfully Cleaned!</source>
        <translation>編譯環境已成功清除!</translation>
    </message>
    <message>
        <source>Build Environments Successfully Cleaned!!</source>
        <translation>編譯環境已成功清除!</translation>
    </message>
    <message>
        <source>Settings Changed</source>
        <translation>設定已變更</translation>
    </message>
    <message>
        <source>Your repositories have changed.
Do you want to Update Your Database?</source>
        <translation>你的套件庫已經變更。
你要更新資料庫嗎?</translation>
    </message>
    <message>
        <source>Mirror Format is incorrect. Your mirror should look like this:
http://mirror.org/$repo/os/i686</source>
        <comment>Obviously keep the example as it is ;)</comment>
        <translation>鏡像格式不正確。應該長得像這個樣子:
http://mirror.org/$repo/os/i686</translation>
    </message>
    <message>
        <source>Your Mirror was successfully added!
It is now available in mirrorlist.</source>
        <comment>mirrorlist here means /etc/pacman.d/mirrorlist, so it should not be translated.</comment>
        <translation>已成功加入你的鏡像!
在鏡像清單中已可使用。</translation>
    </message>
    <message>
        <source>Pacman Database Optimized Successfully!</source>
        <translation>Pacman 資料庫最佳化成功!</translation>
    </message>
    <message>
        <source>Could not Optimize Pacman Database!</source>
        <translation>無法最佳化 Pacman 資料庫!</translation>
    </message>
    <message>
        <source>Operation Completed Successfully!</source>
        <translation>操作成功完成!</translation>
    </message>
    <message>
        <source>Sync was successfully executed!!</source>
        <comment>Sync is always the command</comment>
        <translation>已成功執行同步!!</translation>
    </message>
    <message>
        <source>Sync could not be executed!</source>
        <comment>Sync is always the command</comment>
        <translation>無法執行同步!</translation>
    </message>
    <message>
        <source>Sync could not be executed!!</source>
        <comment>Sync is always the command</comment>
        <translation>無法執行同步!!</translation>
    </message>
    <message>
        <source>Process Selected</source>
        <translation>處理選取的項目</translation>
    </message>
    <message>
        <source>Optimizing Pacman Database...</source>
        <translation>正在最佳化 Pacman 資料庫...</translation>
    </message>
    <message>
        <source>Waiting</source>
        <comment>Waiting for a user action</comment>
        <translation>等待</translation>
    </message>
    <message>
        <source>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Liberation Sans&apos;; font-size:9pt;&quot;&gt;Shaman Manteinance.&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Liberation Sans&apos;; font-size:9pt;&quot;&gt;Please choose an action from the Drop-Down Menu.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;!DOCTYPE HTML PUBLIC &quot;-//W3C//DTD HTML 4.0//EN&quot; &quot;http://www.w3.org/TR/REC-html40/strict.dtd&quot;&gt;
&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Liberation Sans&apos;; font-size:9pt;&quot;&gt;Shaman 維護。&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Liberation Sans&apos;; font-size:9pt;&quot;&gt;請從下拉式選單中選擇一個動作。&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <source>Core</source>
        <comment>Do not translate</comment>
        <translation>Core</translation>
    </message>
    <message>
        <source>Extra</source>
        <comment>Do not translate</comment>
        <translation>Extra</translation>
    </message>
    <message>
        <source>Community</source>
        <comment>Do not translate</comment>
        <translation>Community</translation>
    </message>
    <message>
        <source>Testing</source>
        <comment>Do not translate</comment>
        <translation>Testing</translation>
    </message>
    <message>
        <source>Unstable</source>
        <comment>Do not translate</comment>
        <translation>Unstable</translation>
    </message>
    <message>
        <source>Running sync...</source>
        <comment>sync is a command, so it should not be translated</comment>
        <translation>正在執行同步...</translation>
    </message>
    <message>
        <source>Show Splashscreen</source>
        <translation>顯示啟動畫面</translation>
    </message>
    <message>
        <source>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Liberation Sans&apos;; font-size:9pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Shaman Manteinance.&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Please choose an action from the Drop-Down Menu.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;!DOCTYPE HTML PUBLIC &quot;-//W3C//DTD HTML 4.0//EN&quot; &quot;http://www.w3.org/TR/REC-html40/strict.dtd&quot;&gt;
&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Liberation Sans&apos;; font-size:9pt;&quot;&gt;Shaman 維護。&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Liberation Sans&apos;; font-size:9pt;&quot;&gt;請從下拉式選單中選擇一個動作。&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <source>Process all dependencies and queue from binary first (recommended)</source>
        <translation>先從二進位檔處理全部相依性和佇列 (建議)</translation>
    </message>
    <message>
        <source>Advanced</source>
        <translation>進階</translation>
    </message>
    <message>
        <source>Ok</source>
        <translation>確定</translation>
    </message>
    <message>
        <source>Cancel</source>
        <translation>取消</translation>
    </message>
    <message>
        <source>Use SysLog</source>
        <translation>使用系統日誌</translation>
    </message>
    <message>
        <source>Log File:</source>
        <translation>日誌檔:</translation>
    </message>
    <message>
        <source>KDEMod 3 Testing Repository</source>
        <translation>KDEMod 4 Testing 套件庫</translation>
    </message>
    <message>
        <source>min</source>
        <comment>As in &quot;minutes&quot;</comment>
        <translation>分鐘</translation>
    </message>
    <message>
        <source>Show tray notification Windows</source>
        <translation>顯示收藏匣通知視窗</translation>
    </message>
    <message>
        <source>Use a proxy-server</source>
        <translation>使用代理伺服器</translation>
    </message>
    <message>
        <source>IP:</source>
        <translation>IP:</translation>
    </message>
    <message>
        <source>Port:</source>
        <translation>埠:</translation>
    </message>
    <message>
        <source>HTTP Proxy</source>
        <translation>HTTP 代理</translation>
    </message>
    <message>
        <source>FTP Proxy</source>
        <translation>FTP 代理</translation>
    </message>
    <message>
        <source>Use Shaman RSS Capabilities</source>
        <translation>使用 Shaman RSS 功能</translation>
    </message>
    <message>
        <source>Update RSS Feed Every</source>
        <translation>每隔多久更新 RSS 訂閱</translation>
    </message>
    <message>
        <source>Notify upon new items</source>
        <translation>立即通知新項目</translation>
    </message>
    <message>
        <source>Check if there is an unread news about a package in Queue before processing it</source>
        <translation>處理佇列前檢查是否有與佇列中的套件相關尚未閱讀的新聞</translation>
    </message>
    <message>
        <source>Interface</source>
        <translation>介面</translation>
    </message>
    <message>
        <source>Start Shaman Automatically on X Startup</source>
        <translation>X 啟動時自動執行 Shaman</translation>
    </message>
    <message>
        <source>Forbid starting Shaman as root</source>
        <translation>禁止以 root 身份啟動 Shaman</translation>
    </message>
    <message>
        <source>Saving Configuration</source>
        <translation>儲存設定</translation>
    </message>
    <message>
        <source>Unable to save Pacman configuration!</source>
        <translation>無法儲存 Pacman 設定!</translation>
    </message>
    <message>
        <source>Mirror Format is incorrect. Your mirror should look like this:
http://mirror.org/$repo/$arch</source>
        <comment>Obviously keep the example as it is ;)</comment>
        <translation>鏡像格式不正確。應該長得像這個樣子:
http://mirror.org/$repo/$arch</translation>
    </message>
    <message>
        <source>Your Mirror was successfully added!
It is now available in kdemodmirrorlist.</source>
        <comment>mirrorlist here means /etc/pacman.d/kdemodmirrorlist, so it should not be translated.</comment>
        <translation>已成功加入你的鏡像!
在 kdemod 鏡像清單中已可使用。</translation>
    </message>
    <message>
        <source>Some of your changes have not been applied,
since alpm needs to be released.
You need to restart Shaman to make them effective.</source>
        <translation>你的某些變更還未被套用，
因為需要釋放 alpm。
你需要重新啟動 Shaman 使改變產生作用。</translation>
    </message>
    <message>
        <source>&lt;!DOCTYPE HTML PUBLIC &quot;-//W3C//DTD HTML 4.0//EN&quot; &quot;http://www.w3.org/TR/REC-html40/strict.dtd&quot;&gt;
&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Bitstream Vera Sans&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Liberation Sans&apos;; font-size:9pt;&quot;&gt;Shaman Manteinance.&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Liberation Sans&apos;; font-size:9pt;&quot;&gt;Please choose an action from the Drop-Down Menu.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;!DOCTYPE HTML PUBLIC &quot;-//W3C//DTD HTML 4.0//EN&quot; &quot;http://www.w3.org/TR/REC-html40/strict.dtd&quot;&gt;
&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Liberation Sans&apos;; font-size:9pt;&quot;&gt;Shaman 維護。&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Liberation Sans&apos;; font-size:9pt;&quot;&gt;請從下拉式選單中選擇一個動作。&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <source>&lt;!DOCTYPE HTML PUBLIC &quot;-//W3C//DTD HTML 4.0//EN&quot; &quot;http://www.w3.org/TR/REC-html40/strict.dtd&quot;&gt;
&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Liberation Sans&apos;; font-size:9pt;&quot;&gt;Shaman Manteinance.&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Liberation Sans&apos;; font-size:9pt;&quot;&gt;Please choose an action from the Drop-Down Menu.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;!DOCTYPE HTML PUBLIC &quot;-//W3C//DTD HTML 4.0//EN&quot; &quot;http://www.w3.org/TR/REC-html40/strict.dtd&quot;&gt;
&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Liberation Sans&apos;; font-size:9pt;&quot;&gt;Shaman 維護。&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Liberation Sans&apos;; font-size:9pt;&quot;&gt;請從下拉式選單中選擇一個動作&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <source>RSync Server:</source>
        <translation>同步伺服器:</translation>
    </message>
    <message>
        <source>Update Database at</source>
        <translation>更新資料於</translation>
    </message>
    <message>
        <source>Use Animated Tray Icon</source>
        <translation>使用動畫效果的收藏匣圖示</translation>
    </message>
    <message>
        <source>KDEMod 4 Repository</source>
        <translation>KDEMod 4 套件庫</translation>
    </message>
    <message>
        <source>KDEMod 4 Extragear Repository</source>
        <translation>KDEMod 4 Extragear 套件庫</translation>
    </message>
    <message>
        <source>KDEMod 4 Playground Repository</source>
        <translation>KDEMod 4 Playground 套件庫</translation>
    </message>
    <message>
        <source>KDEMod 4 Testing Repository</source>
        <translation>KDEMod 4 Testing 套件庫</translation>
    </message>
    <message>
        <source>KDEMod 4 Unstable Repository (Testers only!)</source>
        <translation>KDEMod 4 Unstable 套件庫 (僅供測試人員使用!)</translation>
    </message>
    <message>
        <source>Here you can choose what repositories to use between Arch Linux&apos;s official ones. Please note that packages from Unstable and Testing may break your system.</source>
        <translation>你可在這裡選擇要使用哪些 Arch Linux 的官方套件庫。
請注意 Unstable 和 Testing 的套件可能會破壞你的系統。</translation>
    </message>
    <message>
        <source>KDEMod is an improved version of KDE, an Arch Linux exclusive. Featuring an improved Qt build, compatible with Arch Linux standard Qt&apos;s, an improved theme, and lots of addons, KDEMod is the best way to taste the ease and the power of KDE with the simplicity and the power of Arch.</source>
        <translation>KDEMod 是 KDE 的改良版本，Arch Linux 專用。特色有改良的 Qt 編譯、與 Arch Linux 的標準 Qt 相容、改良的主題和許多附加元件，KDEMod 是品嘗 KDE 的舒適強大以及 Arch 簡潔強悍的最好選擇。</translation>
    </message>
    <message>
        <source>You can extend your packages choice by adding other repositories. Third-Party Repositories act just as normal ones, and will be accessible through both Shaman and Pacman.</source>
        <translation>你可以加入其他的套件庫來擴增套件選擇種類。第三方套件庫可作為一般套件庫，而且不論 Shaman 或 Pacman 都可使用。</translation>
    </message>
    <message>
        <source>Use the following language:</source>
        <translation>使用下列語言:</translation>
    </message>
    <message>
        <source>Disable Tray Icon</source>
        <translation>停用收藏匣圖示</translation>
    </message>
</context>
<context>
    <name>EditPBuild</name>
    <message>
        <source>Saving</source>
        <translation>儲存</translation>
    </message>
    <message>
        <source>You modified this PKGBUILD.
Do you want to save it?</source>
        <translation>你修改了這個 PKGBUILD。
你要儲存它嗎?</translation>
    </message>
</context>
<context>
    <name>LocalPackage</name>
    <message>
        <source>Install Package from File</source>
        <translation>從檔案安裝套件</translation>
    </message>
    <message>
        <source>&lt;!DOCTYPE HTML PUBLIC &quot;-//W3C//DTD HTML 4.0//EN&quot; &quot;http://www.w3.org/TR/REC-html40/strict.dtd&quot;&gt;
&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Bitstream Vera Sans&apos;;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Local Package Installation&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;!DOCTYPE HTML PUBLIC &quot;-//W3C//DTD HTML 4.0//EN&quot; &quot;http://www.w3.org/TR/REC-html40/strict.dtd&quot;&gt;
&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Bitstream Vera Sans&apos;;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;本地套件安裝&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <source>Show...</source>
        <translation>顯示...</translation>
    </message>
    <message>
        <source>More Details...</source>
        <translation>更多細節...</translation>
    </message>
    <message>
        <source>Cancel</source>
        <translation>取消</translation>
    </message>
    <message>
        <source>Install Package</source>
        <translation>安裝套件</translation>
    </message>
</context>
<context>
    <name>LocalPackageDialog</name>
    <message>
        <source>Package is not installed</source>
        <translation>套件未被安裝</translation>
    </message>
    <message>
        <source>Version %1 of this package is already installed</source>
        <translation>這個套件的版本 %1 已經安裝</translation>
    </message>
    <message>
        <source>All dependencies are satisfied</source>
        <translation>已滿足所有相依性</translation>
    </message>
    <message>
        <source>%n package(s) will be installed as dependencies</source>
        <translation>將會安裝 %n 個套件以滿足相依性</translation>
    </message>
</context>
<context>
    <name>MainWindow</name>
    <message>
        <source>Shaman</source>
        <translation>Shaman</translation>
    </message>
    <message>
        <source>All packages</source>
        <translation>所有套件</translation>
    </message>
    <message>
        <source>Installed packages</source>
        <translation>已安裝的套件</translation>
    </message>
    <message>
        <source>Not installed packages</source>
        <translation>未安裝的套件</translation>
    </message>
    <message>
        <source>Upgradeable packages</source>
        <translation>可升級的套件</translation>
    </message>
    <message>
        <source>Packages in Queue</source>
        <translation>佇列中的套件</translation>
    </message>
    <message>
        <source>Status</source>
        <translation>狀態</translation>
    </message>
    <message>
        <source>Name</source>
        <translation>名稱</translation>
    </message>
    <message>
        <source>Action</source>
        <translation>動作</translation>
    </message>
    <message>
        <source>Version</source>
        <translation>版本</translation>
    </message>
    <message>
        <source>Size</source>
        <translation>大小</translation>
    </message>
    <message>
        <source>Repository</source>
        <translation>套件庫</translation>
    </message>
    <message>
        <source>Groups</source>
        <translation>群組</translation>
    </message>
    <message>
        <source>Description</source>
        <translation>描述</translation>
    </message>
    <message>
        <source>Action-Text</source>
        <translation>動作名稱</translation>
    </message>
    <message>
        <source>Repositories</source>
        <translation>套件庫</translation>
    </message>
    <message>
        <source>Package Groups</source>
        <translation>套件群組</translation>
    </message>
    <message>
        <source>Package Information</source>
        <translation>套件資訊</translation>
    </message>
    <message>
        <source>Install selected package</source>
        <translation>安裝選取的套件</translation>
    </message>
    <message>
        <source>Mark for Installation</source>
        <translation>標記為安裝</translation>
    </message>
    <message>
        <source>Remove selected package</source>
        <translation>移除選取的套件</translation>
    </message>
    <message>
        <source>Mark for Removal</source>
        <translation>標記為移除</translation>
    </message>
    <message>
        <source>Complete Remove selected package (pacman -Rcs)</source>
        <translation>完整移除選取的套件 (pacman -Rcs)</translation>
    </message>
    <message>
        <source>Mark for complete removal</source>
        <translation>標記為完整移除</translation>
    </message>
    <message>
        <source>Cancel action for selected package</source>
        <translation>取消選取套件的相關動作</translation>
    </message>
    <message>
        <source>Cancel action</source>
        <translation>取消動作</translation>
    </message>
    <message>
        <source>Files</source>
        <translation>檔案</translation>
    </message>
    <message>
        <source>1</source>
        <translation>1</translation>
    </message>
    <message>
        <source>Dependencies</source>
        <translation>相依套件</translation>
    </message>
    <message>
        <source>File</source>
        <translation>檔案</translation>
    </message>
    <message>
        <source>Help</source>
        <translation>說明</translation>
    </message>
    <message>
        <source>Actions</source>
        <translation>動作</translation>
    </message>
    <message>
        <source>Build and Install from Source</source>
        <translation>從原始碼編譯並安裝</translation>
    </message>
    <message>
        <source>Quick Actions</source>
        <translation>快速功能</translation>
    </message>
    <message>
        <source>Package Repositories</source>
        <translation>套件庫</translation>
    </message>
    <message>
        <source>Settings...</source>
        <translation>設定...</translation>
    </message>
    <message>
        <source>About...</source>
        <translation>關於...</translation>
    </message>
    <message>
        <source>Update Database</source>
        <translation>更新資料庫</translation>
    </message>
    <message>
        <source>Upgrade System</source>
        <translation>升級系統</translation>
    </message>
    <message>
        <source>Install Package From File</source>
        <translation>從檔案安裝套件</translation>
    </message>
    <message>
        <source>Update ABS Tree</source>
        <translation>更新 ABS 目錄</translation>
    </message>
    <message>
        <source>Build and Install Queue</source>
        <translation>編譯和安裝佇列</translation>
    </message>
    <message>
        <source>Quit</source>
        <comment>Quit the application</comment>
        <translation>離開</translation>
    </message>
    <message>
        <source>Process Queue</source>
        <translation>處理佇列</translation>
    </message>
    <message>
        <source>Cancel all actions</source>
        <translation>取消所有動作</translation>
    </message>
    <message>
        <source>Settings</source>
        <translation>設定</translation>
    </message>
    <message>
        <source>Shaman - Idle</source>
        <translation>Shaman - 閒置</translation>
    </message>
    <message>
        <source>Shaman will keep running in the system tray.
To close it, click Quit in the file menu or in the tray icon context menu.
While in the System Tray, Shaman will update your Databases
at a regular interval and notify you about available upgrades.
You can change this behaviour in Settings.</source>
        <translation>Shaman 會在收藏匣中繼續執行。
點擊檔案選單中或收藏匣圖示右鍵選單中的「離開」可關閉程式。
當在收藏匣時，Shaman 會定期更新你的資料庫並通知你可升級的相關訊息。
你可在設定中改變這些特性。</translation>
    </message>
    <message>
        <source>Shaman - Reducing To Tray</source>
        <translation>Shaman - 縮至收藏匣</translation>
    </message>
    <message>
        <source>Upgrade</source>
        <translation>升級</translation>
    </message>
    <message>
        <source>Shaman - Idle (Upgrades Available)</source>
        <translation>Shaman - 閒置 (可升級)</translation>
    </message>
    <message>
        <source>System Upgrade</source>
        <translation>系統升級</translation>
    </message>
    <message>
        <source>There is %1 upgradeable package.
Click here to upgrade your System.</source>
        <translation>%1 套件可升級。
點擊這裡升級你的系統。</translation>
    </message>
    <message>
        <source>There are %1 upgradeable packages.
Click here to upgrade your System.</source>
        <translation>%1 套件可升級。
點擊這裡升級你的系統。</translation>
    </message>
    <message>
        <source>All Repositories</source>
        <translation>所有套件庫</translation>
    </message>
    <message>
        <source>Local Packages</source>
        <translation>本地套件</translation>
    </message>
    <message>
        <source>All Groups</source>
        <translation>所有群組</translation>
    </message>
    <message>
        <source>Mark for Reinstallation</source>
        <translation>標記為重新安裝</translation>
    </message>
    <message>
        <source>Install</source>
        <translation>安裝</translation>
    </message>
    <message>
        <source>Uninstall</source>
        <translation>解除安裝</translation>
    </message>
    <message>
        <source>Complete Uninstall</source>
        <translation>完整解除安裝</translation>
    </message>
    <message>
        <source>Status: </source>
        <translation>狀態: </translation>
    </message>
    <message>
        <source>Installed</source>
        <translation>已安裝</translation>
    </message>
    <message>
        <source>Not installed</source>
        <translation>未安裝</translation>
    </message>
    <message>
        <source>Action: </source>
        <translation>動作: </translation>
    </message>
    <message>
        <source>Shaman - Processing</source>
        <translation>Shaman - 處理中</translation>
    </message>
    <message>
        <source>Error</source>
        <translation>錯誤</translation>
    </message>
    <message>
        <source>One or more Databases could not be updated.
Last error reported was:
%1</source>
        <translation>一個或多個資料庫無法更新。
最後的錯誤訊息:
%1</translation>
    </message>
    <message>
        <source>Database Update</source>
        <translation>資料庫更新</translation>
    </message>
    <message>
        <source>Databases Updated Successfully</source>
        <translation>資料庫更新成功</translation>
    </message>
    <message>
        <source>Mark for Upgrade</source>
        <translation>標記為升級</translation>
    </message>
    <message>
        <source>Cancel Action</source>
        <translation>取消動作</translation>
    </message>
    <message>
        <source>Mark all for installation</source>
        <translation>全部標示為安裝</translation>
    </message>
    <message>
        <source>Mark all for reinstallation</source>
        <translation>全部標示為重新安裝</translation>
    </message>
    <message>
        <source>Mark all for removal</source>
        <translation>全部標示為移除</translation>
    </message>
    <message>
        <source>Your system is up to date!</source>
        <translation>你的系統已經是最新狀態!</translation>
    </message>
    <message>
        <source>Queue Processing</source>
        <translation>佇列處理</translation>
    </message>
    <message>
        <source>Your Queue is being processed.
Please wait.</source>
        <translation>你的佇列已開始處理。
請稍候。</translation>
    </message>
    <message>
        <source>Queue Processed</source>
        <translation>佇列已處理</translation>
    </message>
    <message>
        <source>Your Queue was successfully processed!</source>
        <translation>你的佇列已處理成功!</translation>
    </message>
    <message>
        <source>Your Queue was successfully processed!!</source>
        <translation>你的佇列已處理成功!!</translation>
    </message>
    <message>
        <source>To be Installed</source>
        <translation>將會安裝</translation>
    </message>
    <message>
        <source>To be Upgraded</source>
        <translation>將會升級</translation>
    </message>
    <message>
        <source>To be Removed</source>
        <translation>將會移除</translation>
    </message>
    <message>
        <source>Your Queue is about to be processed. You are going to:&lt;br /&gt;</source>
        <translation>即將處理你的佇列。你準備如何:&lt;br /&gt;</translation>
    </message>
    <message>
        <source>Remove &lt;b&gt;%1 package&lt;/b&gt;&lt;br /&gt;</source>
        <translation>移除 &lt;b&gt;%1 套件&lt;/b&gt;&lt;br /&gt;</translation>
    </message>
    <message>
        <source>Remove &lt;b&gt;%1 packages&lt;/b&gt;&lt;br /&gt;</source>
        <translation>移除 &lt;b&gt;%1 套件&lt;/b&gt;&lt;br /&gt;</translation>
    </message>
    <message>
        <source>Install/Upgrade &lt;b&gt;%1 package&lt;/b&gt;&lt;br /&gt;</source>
        <translation>安裝/升級 &lt;b&gt;%1 套件&lt;/b&gt;&lt;br /&gt;</translation>
    </message>
    <message>
        <source>Install/Upgrade &lt;b&gt;%1 packages&lt;/b&gt;&lt;br /&gt;</source>
        <translation>安裝/升級 &lt;b&gt;%1 套件&lt;/b&gt;&lt;br /&gt;</translation>
    </message>
    <message>
        <source>Do you wish to continue?</source>
        <translation>你希望繼續嗎?</translation>
    </message>
    <message>
        <source>Install a Package</source>
        <translation>安裝一個套件</translation>
    </message>
    <message>
        <source>Arch Linux Packages (*.pkg.tar.gz)</source>
        <translation>Arch Linux 套件 (*.pkg.tar.gz)</translation>
    </message>
    <message>
        <source>%1 does not seem
a valid package</source>
        <translation>%1 不是有效的套件</translation>
    </message>
    <message>
        <source>You need to have ABS installed to use Shaman&apos;s
building feature. Do you want to install it now?</source>
        <translation>你必須已經安裝了 ABS 才可以使用 Shaman 的
編譯功能。你要立刻安裝 ABS 嗎?</translation>
    </message>
    <message>
        <source>You can not remove packages when processing
your queue from Source</source>
        <translation>正在從原始碼處理佇列時無法移除套件</translation>
    </message>
    <message>
        <source>Some of your packages do not belong to Arch
Linux&apos;s official repository. Shaman is able to
build packages from official sources only.</source>
        <translation>你的某些套件不屬於 ArchLinux
的官方套件庫。Shaman 只能夠
從官方提供的原始碼編譯套件。</translation>
    </message>
    <message>
        <source>You are about to install &lt;b&gt;%1 package&lt;/b&gt; from source. Building from source&lt;br&gt;can give some advantages, however is very slow.&lt;br&gt;If you are not sure about that, you would probably prefer to process&lt;br&gt;your queue from binary files. Before you continue, you are advised to&lt;br&gt;review your configuration to improve your building performance.</source>
        <translation>你即將要從原始碼安裝 &lt;b&gt;%1 套件&lt;/b&gt;。 從原始碼編譯&lt;br&gt;雖然很慢但會有一些優點。&lt;br&gt;如果您不知道這一點，你可能會寧可&lt;br&gt;從二進位檔案處理你的佇列。建議你繼續進行前&lt;br&gt;檢查你的設定以提高編譯性能。</translation>
    </message>
    <message>
        <source>You are about to install &lt;b&gt;%1 packages&lt;/b&gt; from source. Building from source&lt;br&gt;can give some advantages, however is very slow.&lt;br&gt;If you are not sure about that, you would probably prefer to process&lt;br&gt;your queue from binary files. Before you continue, you are advised to&lt;br&gt;review your configuration to improve your building performance.</source>
        <translation>你即將要從原始碼安裝 &lt;b&gt;%1 套件&lt;/b&gt;。 從原始碼編譯&lt;br&gt;雖然很慢但會有一些優點。&lt;br&gt;如果您不知道這一點，你可能會寧可&lt;br&gt;從二進位檔案處理你的佇列。建議你繼續進行前&lt;br&gt;檢查你的設定以提高編譯性能。</translation>
    </message>
    <message>
        <source>Package Building</source>
        <translation>套件編譯</translation>
    </message>
    <message>
        <source>Your Packages failed to build!</source>
        <translation>你的套件編譯失敗!</translation>
    </message>
    <message>
        <source>Your packages Failed to Build.
Look at the output for more details.</source>
        <translation>你的套件編譯失敗。
查看輸出訊息了解更多細節。</translation>
    </message>
    <message>
        <source>Close</source>
        <translation>關閉</translation>
    </message>
    <message>
        <source>Building Packages Failed!!</source>
        <translation>編譯套件失敗!!</translation>
    </message>
    <message>
        <source>Some packages failed to build.
Do you want to proceed anyway?</source>
        <translation>某些套件編譯失敗。
即使如此你仍要繼續進行嗎?</translation>
    </message>
    <message>
        <source>Install Built Packages</source>
        <translation>安裝編譯好的套件</translation>
    </message>
    <message>
        <source>Close Without Installing</source>
        <translation>不安裝就關閉</translation>
    </message>
    <message>
        <source>Packages Built Successfully!</source>
        <translation>套件編譯成功!</translation>
    </message>
    <message>
        <source>Your Packages have been built successfully, and are ready to be installed</source>
        <translation>你的套件已經成功編譯完成，且準備好可以進行安裝</translation>
    </message>
    <message>
        <source>%1 GiB</source>
        <comment>Size is in Gib</comment>
        <translation>%1 GB</translation>
    </message>
    <message>
        <source>%1 MiB</source>
        <comment>Size is in MiB</comment>
        <translation>%1 MB</translation>
    </message>
    <message>
        <source>%1 KiB</source>
        <comment>Size is in KiB</comment>
        <translation>%1 KB</translation>
    </message>
    <message>
        <source>%1 Bytes</source>
        <comment>Size is in Bytes</comment>
        <translation>%1 位元組</translation>
    </message>
    <message>
        <source>Do not show this Again</source>
        <translation>不再顯示這個訊息</translation>
    </message>
    <message>
        <source>Pacman Update</source>
        <translation>Pacman 更新</translation>
    </message>
    <message>
        <source>Pacman can be upgraded. It is advised to process it alone
to avoid version conflicts.
Do you want to Upgrade Pacman now?</source>
        <translation>Pacman 可升級。建議單獨處理以避免版本衝突。
你想要現在升級 Pacman 嗎?</translation>
    </message>
    <message>
        <source>Shaman Update</source>
        <translation>Shaman 更新</translation>
    </message>
    <message>
        <source>Shaman can be upgraded. It is advised to process it alone
to avoid version conflicts.
Do you want to Upgrade Shaman now?</source>
        <translation>Shaman 可升級。建議單獨處理以避免版本衝突。
你想要現在升級 Shaman 嗎?</translation>
    </message>
    <message>
        <source>Restart required</source>
        <translation>需要重新啟動</translation>
    </message>
    <message>
        <source>Pacman or Shaman was updated. Shaman will now quit,
please restart it to use the new version</source>
        <translation>Pacman 或 Shaman 已更新。 Shaman 將會關閉，
請重新啟動程式來使用新版本</translation>
    </message>
    <message>
        <source>Library Question</source>
        <translation>函式庫問題</translation>
    </message>
    <message>
        <source>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;A libalpm frontend in Qt&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;License: GPLv2+&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Libalpm Version: v.%1&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;(C) 2008 Dario Freddi &amp;lt;drf54321@yahoo.it&amp;gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;(C) 2008 Lukas Appelhans &amp;lt;l.appelhans@gmx.de&amp;gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;一個 libalpm 的 Qt 前端&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;授權: GPLv2+&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Libalpm 版本: v.%1&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;(C) 2008 Dario Freddi &amp;lt;drf54321@yahoo.it&amp;gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;(C) 2008 Lukas Appelhans &amp;lt;l.appelhans@gmx.de&amp;gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <source>Local Version: </source>
        <translation>本地版本: </translation>
    </message>
    <message>
        <source>Version in the Repository: </source>
        <translation>於套件庫中的版本: </translation>
    </message>
    <message>
        <source>One or more errors occourred, your Queue
was not successfully processed</source>
        <translation>發生一個或多個錯誤，你的佇列處理失敗</translation>
    </message>
    <message>
        <source>Esc</source>
        <translation>Esc</translation>
    </message>
    <message>
        <source>News Alert</source>
        <translation>新聞通知</translation>
    </message>
    <message>
        <source>There is an unread news about %1.
Do you want to read it?</source>
        <translation>有一則尚未閱讀的新聞 %1。
你想要閱讀嗎?</translation>
    </message>
    <message>
        <source>Your Kernel has been updated.
Please restart your PC soon to load the new Kernel.</source>
        <translation>你的內核已經更新。
請重新啟動你的電腦來載入新內核。</translation>
    </message>
    <message>
        <source>Tools</source>
        <translation>工具</translation>
    </message>
    <message>
        <source>Read News</source>
        <translation>閱讀新聞</translation>
    </message>
    <message>
        <source>View Log</source>
        <translation>檢視日誌</translation>
    </message>
    <message>
        <source>One or more errors occurred, your Queue
was not successfully processed</source>
        <translation>發生一個或多個錯誤，你的佇列處理失敗</translation>
    </message>
    <message>
        <source>One or more databases failed to update!</source>
        <translation>一個或多個資料庫無法更新!</translation>
    </message>
    <message>
        <source>Error Processing Queue!!</source>
        <translation>處理佇列發生錯誤!!</translation>
    </message>
    <message>
        <source>A package providing %1 is already installed.
Do you want to install %1 anyway?</source>
        <translation>套件提供的 %1 已安裝。
即使如此仍要安裝 %1 嗎?</translation>
    </message>
    <message>
        <source>&amp;File</source>
        <translation>檔案(&amp;F)</translation>
    </message>
    <message>
        <source>&amp;Help</source>
        <translation>說明(&amp;H)</translation>
    </message>
    <message>
        <source>&amp;Actions</source>
        <translation>動作(&amp;A)</translation>
    </message>
    <message>
        <source>&amp;Tools</source>
        <translation>工具(&amp;T)</translation>
    </message>
    <message>
        <source>Re&amp;positories</source>
        <translation>套件庫(&amp;P)</translation>
    </message>
    <message>
        <source>Package &amp;Groups</source>
        <translation>套件群組(&amp;G)</translation>
    </message>
    <message>
        <source>Mark for &amp;Installation</source>
        <translation>標記為安裝(&amp;I)</translation>
    </message>
    <message>
        <source>Mark for &amp;Removal</source>
        <translation>標記為移除(&amp;R)</translation>
    </message>
    <message>
        <source>Mark for complete re&amp;moval</source>
        <translation>標記為完整移除(&amp;M)</translation>
    </message>
    <message>
        <source>Package I&amp;nformation</source>
        <translation>套件資訊(&amp;N)</translation>
    </message>
    <message>
        <source>File&amp;s</source>
        <translation>檔案(&amp;S)</translation>
    </message>
    <message>
        <source>&amp;Dependencies</source>
        <translation>相依套件(&amp;D)</translation>
    </message>
    <message>
        <source>Mark for Re&amp;installation</source>
        <translation>標記為重新安裝(&amp;I)</translation>
    </message>
    <message>
        <source>&amp;Cancel Action</source>
        <translation>取消動作(&amp;C)</translation>
    </message>
    <message>
        <source>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;A libalpm frontend in Qt&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;License: GPLv2+&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Libalpm Version: v.%1&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;(C) 2008 Dario Freddi &amp;lt;drf@kdemod.ath.cx&amp;gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;(C) 2008 Lukas Appelhans &amp;lt;boom1992@kdemod.ath.cx&amp;gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;一個 libalpm 的 Qt 前端&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;授權: GPLv2+&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Libalpm 版本: v.%1&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;(C) 2008 Dario Freddi &amp;lt;drf@kdemod.ath.cx&amp;gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;(C) 2008 Lukas Appelhans &amp;lt;boom1992@kdemod.ath.cx&amp;gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <source>Ctrl+Q</source>
        <comment>Exit Shaman Shortcut</comment>
        <translation>Ctrl+Q</translation>
    </message>
    <message>
        <source>Name and Description</source>
        <translation>名稱和描述</translation>
    </message>
</context>
<context>
    <name>MaintenanceBar</name>
    <message>
        <source>Please choose an action to start maintenance...</source>
        <translation>請選擇一個動作開始進行維護...</translation>
    </message>
    <message>
        <source>Clean Unused Databases</source>
        <translation>清除未使用的資料庫</translation>
    </message>
    <message>
        <source>Clean Cache</source>
        <translation>清除快取</translation>
    </message>
    <message>
        <source>Empty Cache</source>
        <translation>清空快取</translation>
    </message>
    <message>
        <source>Optimize Pacman Database</source>
        <translation>最佳化 Pacman 資料庫</translation>
    </message>
    <message>
        <source>Clean All Building Environments</source>
        <translation>清除所有編譯環境</translation>
    </message>
    <message>
        <source>Cleaning up unused Databases...</source>
        <translation>清理未使用的資料庫...</translation>
    </message>
    <message>
        <source>Cleaning up Cache...</source>
        <translation>正在清理快取...</translation>
    </message>
    <message>
        <source>Deleting Cache...</source>
        <translation>正在刪除快取...</translation>
    </message>
    <message>
        <source>Optimizing Pacman Database...</source>
        <translation>正在最佳化 Pacman 資料庫...</translation>
    </message>
    <message>
        <source>Cleaning up building Environments...</source>
        <translation>正在清理編譯環境...</translation>
    </message>
    <message>
        <source>Abort</source>
        <translation>中止</translation>
    </message>
    <message>
        <source>System Maintenance</source>
        <translation>系統維護</translation>
    </message>
    <message>
        <source>Unused Databases Cleaned up successfully!</source>
        <translation>未使用的資料庫清理成功!</translation>
    </message>
    <message>
        <source>Cache Cleaned Up Successfully!</source>
        <translation>快取已清理成功!</translation>
    </message>
    <message>
        <source>Cache Successfully Deleted!</source>
        <translation>快取已成功刪除!</translation>
    </message>
    <message>
        <source>Build Environments Successfully Cleaned!</source>
        <translation>編譯環境已清理成功!</translation>
    </message>
    <message>
        <source>Close</source>
        <translation>關閉</translation>
    </message>
    <message>
        <source>Cleaning up Unused Databases Failed!</source>
        <translation>清理未使用的資料庫失敗!</translation>
    </message>
    <message>
        <source>Cleaning up Cache Failed!</source>
        <translation>清理快取失敗!</translation>
    </message>
    <message>
        <source>Deleting Cache Failed!</source>
        <translation>刪除快取失敗!</translation>
    </message>
    <message>
        <source>Could not clean Build Environments!!</source>
        <translation>無法清除編譯環境!!</translation>
    </message>
    <message>
        <source>Pacman Database Optimized Successfully!</source>
        <translation>Pacman 資料庫最佳化成功!</translation>
    </message>
    <message>
        <source>Could not Optimize Pacman Database!</source>
        <translation>無法最佳化 Pacman 資料庫!</translation>
    </message>
    <message>
        <source>Running sync...</source>
        <comment>sync is a command, so it should not be translated</comment>
        <translation>正在執行同步...</translation>
    </message>
    <message>
        <source>Operation Completed Successfully!</source>
        <translation>操作成功完成!</translation>
    </message>
    <message>
        <source>Sync was successfully executed!!</source>
        <comment>Sync is always the command</comment>
        <translation>已成功執行同步!!</translation>
    </message>
    <message>
        <source>Sync could not be executed!</source>
        <comment>Sync is always the command</comment>
        <translation>無法執行同步!</translation>
    </message>
    <message>
        <source>Sync could not be executed!!</source>
        <comment>Sync is always the command</comment>
        <translation>無法執行同步!</translation>
    </message>
    <message>
        <source>Maintenance Actions</source>
        <translation>維護動作</translation>
    </message>
</context>
<context>
    <name>NewsViewer</name>
    <message>
        <source>Please wait, fetching items...</source>
        <translation>請稍候，正在取得新聞...</translation>
    </message>
    <message>
        <source>Mark as Read</source>
        <translation>標記為已閱讀</translation>
    </message>
    <message>
        <source>Mark as Unread</source>
        <translation>標記為尚未閱讀</translation>
    </message>
    <message>
        <source>Error</source>
        <translation>錯誤</translation>
    </message>
    <message>
        <source>Could not fetch the RSS feed! Error reported was:</source>
        <translation>無法取得 RSS 訂閱! 錯誤訊息如下:</translation>
    </message>
</context>
<context>
    <name>PackageProperties</name>
    <message>
        <source>%1 GiB</source>
        <comment>Size is in Gib</comment>
        <translation>%1 GB</translation>
    </message>
    <message>
        <source>%1 MiB</source>
        <comment>Size is in MiB</comment>
        <translation>%1 MB</translation>
    </message>
    <message>
        <source>%1 KiB</source>
        <comment>Size is in KiB</comment>
        <translation>%1 KB</translation>
    </message>
    <message>
        <source>%1 Bytes</source>
        <comment>Size is in Bytes</comment>
        <translation>%1 位元組</translation>
    </message>
    <message>
        <source>Shaman - %1 properties</source>
        <translation>Shaman - %1 屬性</translation>
    </message>
    <message>
        <source>N/A</source>
        <comment>Stands for: Not Available</comment>
        <translation>無效</translation>
    </message>
    <message>
        <source>Changelog not available for this package</source>
        <translation>這個套件無更改日誌</translation>
    </message>
</context>
<context>
    <name>QObject</name>
    <message>
        <source>You have to be root to run Shaman.
Please restart it with root privileges.</source>
        <translation>Shaman 不能以 root 身份啟動。
請以普通使用者重新啟動。</translation>
    </message>
    <message>
        <source>Shaman</source>
        <translation>Shaman</translation>
    </message>
    <message>
        <source>There was a problem while testing libalpm.
Maybe another application has a lock on it.</source>
        <translation>當測試 libalpm 時發生問題。
可能其他應用程式鎖住它了。</translation>
    </message>
    <message>
        <source>Please Wait...</source>
        <translation>請稍等...</translation>
    </message>
    <message>
        <source>Loading Databases...</source>
        <translation>載入資料庫...</translation>
    </message>
    <message>
        <source>Loading Packages...</source>
        <translation>載入套件...</translation>
    </message>
    <message>
        <source>Starting up Shaman...</source>
        <translation>正在啟動 Shaman...</translation>
    </message>
    <message>
        <source>Pacman is not updated.
Shaman needs libalpm &gt;= 2.1.0 to run.
Yours is %1. Please update Pacman.</source>
        <translation>Pacman 尚未更新。
Shaman 需要 libalpm &gt;= 2.1.0 來執行
你的版本為 %1。 請更新 Pacman。</translation>
    </message>
    <message>
        <source>Ok</source>
        <translation>確定</translation>
    </message>
    <message>
        <source>Yes</source>
        <translation>是</translation>
    </message>
    <message>
        <source>No</source>
        <translation>否</translation>
    </message>
    <message>
        <source>Your settings file seems unwritable.
Please check permissions on it.</source>
        <translation>你的設定檔似乎無法讀取。
請檢查設定檔的權限。</translation>
    </message>
    <message>
        <source>You have started Shaman as root.
It is advised to start it as unprivileged user.
Shaman will ask you for root password when needed.</source>
        <translation>你已經用 root 身份啟動 Shaman。
建議以普通使用者身份啟動程式。
Shaman 會在需要時詢問你 root 密碼。</translation>
    </message>
    <message>
        <source>It looks like another copy of Shaman is running.
You can only run one copy of Shaman at a time.</source>
        <translation>另一個 Shaman 正在執行中。
你只能一次執行一個 Shaman。</translation>
    </message>
    <message>
        <source>Shaman can not be started as root.
Please restart it as unprivileged user.</source>
        <translation>Shaman 不能以 root 身份啟動。
請以普通使用者重新啟動。</translation>
    </message>
    <message>
        <source>Shaman could not switch to root.
Probably you have not set the SUID bit to it.
You can do that by issuing as root
chown root shaman &amp;&amp; chmod u+s shaman.
Note that this is safe, please read Shaman wiki
for more details.</source>
        <translation>Shaman 無法切換為 root 身份。
可能你沒有設定 SUID 片段給它。
遇到 root 問題時你可執行這些指令
chown root shaman &amp;&amp; chmod u+s shaman。
注意這個動作是安全的，請閱讀 Shaman wiki
來獲得更多細節資訊。</translation>
    </message>
    <message>
        <source>Do not show this Again</source>
        <translation>不再顯示這個訊息</translation>
    </message>
    <message>
        <source>O&amp;k</source>
        <translation>確定(&amp;K)</translation>
    </message>
    <message>
        <source>&amp;Yes</source>
        <translation>是(&amp;Y)</translation>
    </message>
    <message>
        <source>&amp;No</source>
        <translation>否(&amp;N)</translation>
    </message>
    <message>
        <source>Do not &amp;show this Again</source>
        <translation>不再顯示這個訊息(&amp;S)</translation>
    </message>
    <message>
        <source>C&amp;ancel</source>
        <translation>取消(&amp;A)</translation>
    </message>
    <message>
        <source>Whoa, that&apos;s co&amp;ol!</source>
        <translation>哇啊，好棒喔(&amp;O)!</translation>
    </message>
</context>
<context>
    <name>QueueDialog</name>
    <message>
        <source>&lt;br&gt;&lt;b&gt; * Validating Transaction&lt;/b&gt;&lt;br&gt;</source>
        <translation>&lt;br&gt;&lt;b&gt; * 確認執行項目&lt;/b&gt;&lt;br&gt;</translation>
    </message>
    <message>
        <source>Validating Dependencies...</source>
        <translation>正在確認相依性...</translation>
    </message>
    <message>
        <source>Checking for Conflicts...</source>
        <translation>正在檢查衝突...</translation>
    </message>
    <message>
        <source>Resolving Dependencies...</source>
        <translation>正在解決相依性...</translation>
    </message>
    <message>
        <source>Looking for Inter-Conflicts...</source>
        <translation>正在尋找內部衝突...</translation>
    </message>
    <message>
        <source>&lt;br&gt;&lt;b&gt; * Package Installation Started&lt;/b&gt;&lt;br&gt;</source>
        <translation>&lt;br&gt;&lt;b&gt; * 套件安裝開始&lt;/b&gt;&lt;br&gt;</translation>
    </message>
    <message>
        <source>Installing %1...</source>
        <translation>正在安裝 %1...</translation>
    </message>
    <message>
        <source>%1 (%2) installed successfully!</source>
        <translation>%1 (%2) 已成功安裝!</translation>
    </message>
    <message>
        <source>&lt;br&gt;&lt;b&gt; * Package Removal Started&lt;/b&gt;&lt;br&gt;</source>
        <translation>&lt;br&gt;&lt;b&gt; * 套件移除開始&lt;/b&gt;&lt;br&gt;</translation>
    </message>
    <message>
        <source>Removing %1...</source>
        <translation>正在移除 %1...</translation>
    </message>
    <message>
        <source>%1 (%2) removed successfully!</source>
        <translation>%1 (%2) 已成功移除!</translation>
    </message>
    <message>
        <source>&lt;br&gt;&lt;b&gt; * Package Upgrading Started&lt;/b&gt;&lt;br&gt;</source>
        <translation>&lt;br&gt;&lt;b&gt; * 套件升級開始&lt;/b&gt;&lt;br&gt;</translation>
    </message>
    <message>
        <source>Upgrading %1...</source>
        <translation>正在升級 %1...</translation>
    </message>
    <message>
        <source>Upgraded %1 successfully (%2 -&gt; %3)</source>
        <translation>已成功升級 %1 (%2 -&gt; %3)</translation>
    </message>
    <message>
        <source>&lt;br&gt;&lt;b&gt; * Queue Processing Started&lt;/b&gt;&lt;br&gt;</source>
        <translation>&lt;br&gt;&lt;b&gt; * 佇列處理開始&lt;/b&gt;&lt;br&gt;</translation>
    </message>
    <message>
        <source>Checking package integrity...</source>
        <translation>檢查套件完整性...</translation>
    </message>
    <message>
        <source>Checking delta integrity...</source>
        <translation>正在檢查修補的完整性...</translation>
    </message>
    <message>
        <source>Applying deltas...</source>
        <translation>正在套用修補...</translation>
    </message>
    <message>
        <source>Generating %1 with %2... </source>
        <translation>正載以 %2 生成 %1... </translation>
    </message>
    <message>
        <source>Success!</source>
        <translation>成功!</translation>
    </message>
    <message>
        <source>Failed!</source>
        <translation>失敗!</translation>
    </message>
    <message>
        <source>&lt;br&gt;&lt;b&gt; * Package Downloading Started&lt;/b&gt;&lt;br&gt;</source>
        <translation>&lt;br&gt;&lt;b&gt; * 套件下載已經開始&lt;/b&gt;&lt;br&gt;</translation>
    </message>
    <message>
        <source>Starting downloading packages from %1...</source>
        <translation>從 %1 開始下載套件...</translation>
    </message>
    <message>
        <source>%p% (%1 KB/s, %4:%5:%6 remaining)</source>
        <comment>You just have to translate &apos;remaining&apos; here. Leave everything else as it is.</comment>
        <translation>%p% (%1 KB/s,剩餘時間 %4:%5:%6)</translation>
    </message>
    <message>
        <source>Downloading %1... (%2 MB of %3 MB)</source>
        <translation>正在下載 %1... (%3 MB 已下載 %2 MB)</translation>
    </message>
    <message>
        <source>Downloading %1... (%2 KB of %3 KB)</source>
        <translation>正在下載 %1... (%3 KB 已下載 %2 KB)</translation>
    </message>
    <message>
        <source>Queue processed, please wait...</source>
        <translation>佇列開始處理，請稍候...</translation>
    </message>
    <message>
        <source>Executing pre_install scriptlet...</source>
        <translation>正在執行 pre_install 程式敘述...</translation>
    </message>
    <message>
        <source>Executing pre_upgrade scriptlet...</source>
        <translation>正在執行 pre_upgrade 程式敘述...</translation>
    </message>
    <message>
        <source>Executing pre_remove scriptlet...</source>
        <translation>正在執行 pre_remove 程式敘述...</translation>
    </message>
    <message>
        <source>Executing post_install scriptlet...</source>
        <translation>正在執行 post_install 程式敘述...</translation>
    </message>
    <message>
        <source>Executing post_upgrade scriptlet...</source>
        <translation>正在執行 post_upgrade 程式敘述...</translation>
    </message>
    <message>
        <source>Executing post_remove scriptlet...</source>
        <translation>正在執行 post_remove 程式敘述...</translation>
    </message>
    <message>
        <source>Unexpected Error. Shaman might be corrupted.</source>
        <translation>不預期的錯誤。Shaman 可能已損毀。</translation>
    </message>
    <message>
        <source>Extracting Scriptlet from package failed!!</source>
        <translation>從套件執行程式敘述失敗!!</translation>
    </message>
    <message>
        <source>Scriptlet processed successfully!</source>
        <translation>程式敘述處理成功!</translation>
    </message>
    <message>
        <source>Scriptlet not found in this stage, or error processing it!</source>
        <translation>Script non-trouvé à cette étape, ou il y a eu une erreur dans son exécution!</translation>
    </message>
    <message>
        <source>Executing %1 scriptlet for %2...</source>
        <translation>正在執行 %2 的 %1 程式敘述...</translation>
    </message>
    <message>
        <source>Package %1 does not have %2 scriptlet</source>
        <translation>套件 %1 沒有 %2 程式敘述</translation>
    </message>
    <message>
        <source>Error processing Scriptlet!!</source>
        <translation>處理程式敘述錯誤!!</translation>
    </message>
    <message>
        <source>Queue Processing</source>
        <translation>處理佇列</translation>
    </message>
    <message>
        <source>There has been an error while preparing the transaction.
</source>
        <translation>當準備執行項目時發生錯誤。
</translation>
    </message>
    <message>
        <source>There has been an error while committing the transaction.
</source>
        <translation>當提交執行項目時發生錯誤。
</translation>
    </message>
    <message>
        <source>Queue processing failed!</source>
        <translation>佇列處理失敗!</translation>
    </message>
    <message>
        <source>Queue processed successfully!</source>
        <translation>佇列已成功處理!</translation>
    </message>
    <message>
        <source>Close</source>
        <translation>關閉</translation>
    </message>
    <message>
        <source>Would you like to abort Queue Processing?
This may damage your system.</source>
        <translation>你要中止處理佇列嗎?
這樣可能會損害你的系統。</translation>
    </message>
    <message>
        <source>Ok</source>
        <translation>確定</translation>
    </message>
</context>
<context>
    <name>QueueReadyDialog</name>
    <message>
        <source>Review Queue</source>
        <translation>重新檢視佇列</translation>
    </message>
    <message>
        <source>Turn off PC when Queue is done</source>
        <translation>佇列處理結束時關閉電腦</translation>
    </message>
    <message>
        <source>Process in Tray</source>
        <translation>在收藏匣中進行處理</translation>
    </message>
    <message>
        <source>Show packages...</source>
        <translation>顯示套件...</translation>
    </message>
    <message>
        <source>Packages In Queue</source>
        <translation>佇列中的套件</translation>
    </message>
    <message>
        <source>Cancel</source>
        <translation>取消</translation>
    </message>
    <message>
        <source>Process</source>
        <translation>處理</translation>
    </message>
    <message>
        <source>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Review Queue&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;重新檢視佇列&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <source>Keep Queue Dialog Open after the Queue is finished</source>
        <translation>佇列處理完成後不要關閉佇列對話窗</translation>
    </message>
    <message>
        <source>Force Queue Processing</source>
        <translation>強制處理佇列</translation>
    </message>
</context>
<context>
    <name>ReviewQueueDialog</name>
    <message>
        <source>Install</source>
        <translation>安裝</translation>
    </message>
    <message>
        <source>To be Installed</source>
        <translation>將要安裝</translation>
    </message>
    <message>
        <source>Upgrade</source>
        <translation>升級</translation>
    </message>
    <message>
        <source>To be Upgraded</source>
        <translation>將要升級</translation>
    </message>
    <message>
        <source>Uninstall</source>
        <translation>解除安裝</translation>
    </message>
    <message>
        <source>To be Removed</source>
        <translation>將會移除</translation>
    </message>
    <message>
        <source>Complete Uninstall</source>
        <translation>完整解除安裝</translation>
    </message>
    <message>
        <source>Your Queue is about to be processed. You are going to:&lt;br /&gt;</source>
        <translation>即將處理你的佇列。你準備如何:&lt;br /&gt;</translation>
    </message>
    <message>
        <source>Remove &lt;b&gt;%1 package&lt;/b&gt;&lt;br /&gt;</source>
        <translation>移除 &lt;b&gt;%1 套件&lt;/b&gt;&lt;br /&gt;</translation>
    </message>
    <message>
        <source>Remove &lt;b&gt;%1 packages&lt;/b&gt;&lt;br /&gt;</source>
        <translation>移除 &lt;b&gt;%1 套件&lt;/b&gt;&lt;br /&gt;</translation>
    </message>
    <message>
        <source>Install/Upgrade &lt;b&gt;%1 package&lt;/b&gt;&lt;br /&gt;</source>
        <translation>安裝/升級 &lt;b&gt;%1 套件&lt;/b&gt;&lt;br /&gt;</translation>
    </message>
    <message>
        <source>Install/Upgrade &lt;b&gt;%1 packages&lt;/b&gt;&lt;br /&gt;</source>
        <translation>安裝/升級 &lt;b&gt;%1 套件&lt;/b&gt;&lt;br /&gt;</translation>
    </message>
    <message>
        <source>Do you wish to continue?</source>
        <translation>你希望繼續嗎?</translation>
    </message>
    <message>
        <source>&lt;b&gt;%1&lt;/b&gt; will be used</source>
        <translation>將會用掉 &lt;b&gt;%1&lt;/b&gt;</translation>
    </message>
    <message>
        <source>&lt;b&gt;%1&lt;/b&gt; will be freed</source>
        <translation>將會釋放 &lt;b&gt;%1&lt;/b&gt;</translation>
    </message>
    <message>
        <source>Remove &lt;b&gt;%n package(s)&lt;/b&gt;&lt;br /&gt;</source>
        <translation>移除 &lt;b&gt;%n 套件&lt;/b&gt;&lt;br /&gt;</translation>
    </message>
    <message>
        <source>Install/Upgrade &lt;b&gt;%n package(s)&lt;/b&gt;&lt;br /&gt;</source>
        <translation>安裝/升級 &lt;b&gt;%n 套件&lt;/b&gt;&lt;br /&gt;</translation>
    </message>
</context>
<context>
    <name>ShamanStatusBar</name>
    <message>
        <source>%1 Available Packages, %2 Installed Packages, %3 Upgradeable Packages</source>
        <translation>%1 個可用的套件, %2 個已安裝的套件, %3 個可升級的套件</translation>
    </message>
    <message>
        <source>%1 will be used</source>
        <translation>將會用掉 %1</translation>
    </message>
    <message>
        <source>%1 will be freed</source>
        <translation>將會釋放 %1</translation>
    </message>
    <message>
        <source>%1 to be Installed, %2 to be Removed</source>
        <translation>%1 個將要安裝, %2 個將要移除</translation>
    </message>
</context>
<context>
    <name>ShamanTrayIcon</name>
    <message>
        <source>Update Database</source>
        <translation>更新資料庫</translation>
    </message>
    <message>
        <source>Upgrade System</source>
        <translation>升級系統</translation>
    </message>
    <message>
        <source>Process Queue</source>
        <translation>處理佇列</translation>
    </message>
    <message>
        <source>Settings</source>
        <translation>設定</translation>
    </message>
    <message>
        <source>Quit</source>
        <translation>離開</translation>
    </message>
    <message>
        <source>Shaman - Idle</source>
        <translation>Shaman - 閒置</translation>
    </message>
    <message>
        <source>Shaman - Processing</source>
        <translation>Shaman - 處理中</translation>
    </message>
    <message>
        <source>Shaman - Idle (Upgrades Available)</source>
        <translation>Shaman - 閒置 (可升級)</translation>
    </message>
    <message>
        <source>System Upgrade</source>
        <translation>系統升級</translation>
    </message>
    <message>
        <source>There is %1 upgradeable package.
Click here to upgrade your System.</source>
        <translation>%1 套件可升級。
點擊這裡升級你的系統。</translation>
    </message>
    <message>
        <source>There are %1 upgradeable packages.
Click here to upgrade your System.</source>
        <translation>%1 套件可升級。
點擊這裡升級你的系統。</translation>
    </message>
    <message>
        <source>New News Available</source>
        <translation>有新的新聞</translation>
    </message>
    <message>
        <source>There are new news available.
Click here to review them.</source>
        <translation>有新的新聞。
點擊這裡來重新檢視。</translation>
    </message>
    <message>
        <source>Failed Fetching News</source>
        <translation>取得新聞失敗</translation>
    </message>
    <message>
        <source>An error occourred while fetching news!
Click here to open the News Dialog for more details.</source>
        <translation>當取得新聞時發生一個錯誤!
點擊這裡開啟新聞對話窗以獲得更多細節。</translation>
    </message>
    <message>
        <source>Upgradeable package(s): %n.
Click here to upgrade your System.</source>
        <translation>可升級的套件: %n.
點擊這裡以升級你的系統。</translation>
    </message>
</context>
<context>
    <name>SysUpgradeDialog</name>
    <message>
        <source>There is &lt;b&gt;%1 upgradeable package&lt;/b&gt;. You can either&lt;br&gt; upgrade immediately or add it to the current Queue&lt;br&gt; and process it later.</source>
        <translation>&lt;b&gt;%1 套件可升級&lt;/b&gt; 。你可以&lt;br&gt;立刻升級或者增加到目前的佇列&lt;br&gt;稍候再執行升級。</translation>
    </message>
    <message>
        <source>There are &lt;b&gt;%1 upgradeable packages&lt;/b&gt;. You can either&lt;br&gt; upgrade immediately or add them to the current Queue&lt;br&gt; and process them later.</source>
        <translation>&lt;b&gt;%1 套件可升級&lt;/b&gt; 。你可以&lt;br&gt;立刻升級或者增加到目前的佇列&lt;br&gt;稍候再執行升級。</translation>
    </message>
    <message>
        <source>To be Upgraded</source>
        <translation>將會升級</translation>
    </message>
    <message>
        <source>&lt;b&gt;Upgradeable package(s): %n&lt;/b&gt; You can either&lt;br&gt; upgrade immediately or add it to the current Queue&lt;br&gt; and process it later.</source>
        <translation>&lt;b&gt;可升級套件: %n&lt;/b&gt; 你可以&lt;br&gt; 立刻升級或者增加到目前的佇列&lt;br&gt;稍候再執行升級。</translation>
    </message>
</context>
<context>
    <name>aboutDialog</name>
    <message>
        <source>About Shaman</source>
        <translation>關於 Shaman</translation>
    </message>
    <message>
        <source>About</source>
        <translation>關於</translation>
    </message>
    <message>
        <source>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;A libalpm frontend in Qt&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;License: GPLv2+&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;(C) 2008 Dario Freddi &amp;lt;drf54321@yahoo.it&amp;gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;(C) 2008 Lukas Appelhans &amp;lt;l.appelhans@gmx.de&amp;gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;一個 libalpm 的 Qt 前端&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;授權: GPLv2+&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;(C) 2008 Dario Freddi &amp;lt;drf54321@yahoo.it&amp;gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;(C) 2008 Lukas Appelhans &amp;lt;l.appelhans@gmx.de&amp;gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <source>Authors</source>
        <translation>作者</translation>
    </message>
    <message>
        <source>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Dario Freddi&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Developer&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Lukas Appelhans&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;Developer&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Dario Freddi&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;開發者&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Lukas Appelhans&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;開發者&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <source>Thanks To</source>
        <translation>感謝</translation>
    </message>
    <message>
        <source>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Liberation Sans&apos;; font-size:9pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-size:14pt; font-weight:600;&quot;&gt;Shaman 1.0 Alpha (revision 336)&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Liberation Sans&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Shaman 1.0 Alpha (修訂版 336)&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <source>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Liberation Sans&apos;; font-size:9pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Shaman has received a lot of help from a lot of people, and it is also thanks to them if Shaman has seen the light. If we forgot to add you here, let us know.&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:600;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:600;&quot;&gt;Jan Mette&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;German Translation and KDEMod-Developer&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Johannes Schriewer&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:10pt; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;KDEMod Developer, and also some help on the code.&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:600;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;uzbirglones&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Brazilian Translator, and gave the name Shaman&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Martin Sandsmark&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Our hoster, and maintainer of Trac.&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;mutlu_inek&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;Heavy tester, thanks!&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;KDEMod Community&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;Help, Testing, Support, everything started from here.&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;FenDanT&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;French Translator&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;XanK&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Spanish Translator&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;augegr&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Greek Translator&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Liberation Sans&apos;; font-size:9pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Shaman a reçu beaucoup d&apos;aide de beaucoup de gens, et c&apos;est aussi grâce à eux si Shaman a vu le jour. Si nous avon oublié de vous ajouter ici, faites-le nous savoir.&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:600;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:600;&quot;&gt;Jan Mette&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Traduction allemande et developpeur KDEMod&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Johannes Schriewer&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:10pt; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;developpeur KDEMod, et également aide à propos du code.&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:600;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;uzbirglones&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Traduction brésilienne et père du nom Shaman&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Martin Sandsmark&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Notre hébergeur et maintenteur du Trac.&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;mutlu_inek&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;Super-Testeur, Merci !&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;La communauté KDEMod&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;L&apos;aide, les tests, le support, tout a commencé ici.&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;FenDanT : Jacques Disner from http://www.archlinux.fr&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Traduction française&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;XanK&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Traduction espagnole&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;augegr&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Traduction grecque&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <source>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Liberation Sans&apos;; font-size:9pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-size:14pt; font-weight:600;&quot;&gt;Shaman 1.0 Alpha (revision 450)&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Liberation Sans&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Shaman 1.0 Alpha (修訂版 450)&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <source>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Liberation Sans&apos;; font-size:9pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Shaman has received a lot of help from a lot of people, and it is also thanks to them if Shaman has seen the light. If we forgot to add you here, let us know.&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:600;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:600;&quot;&gt;Jan Mette&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;German Translation and KDEMod-Developer&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Johannes Schriewer&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:10pt; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;KDEMod Developer, and also some help on the code.&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:600;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Rodrigo Mazak&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Brazilian Translator, and gave the name Shaman&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Martin Sandsmark&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Our hoster, and maintainer of Trac.&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Till Luge&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;Heavy tester, thanks!&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;KDEMod Community&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;Help, Testing, Support, everything started from here.&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Jacques Disner&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;French Translator&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;XanK&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Spanish Translator&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Giannis Antoniou&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Greek Translator&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Liberation Sans&apos;; font-size:9pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Shaman a obtenu de l&apos;aide de nombreuse personnes, et c&apos;est également grâce à eux si Shaman a vu le jour. Si nous avons oublié de vous mentionner ici, faites le nous savoir.&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:600;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:600;&quot;&gt;Jan Mette&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Traduction allemande et developpeur KDEMod&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Johannes Schriewer&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:10pt; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;Developpeur KDEMod, et également particiaption au codage.&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:600;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Rodrigo Mazak&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Traduction brésilienne et découvreur du nom Shaman&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Martin Sandsmark&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Notre hébergeur, et mainteneur du Trac.&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Till Luge&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;Super-testeur, Merci!&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;La communauté KDEMod&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;Aide, tests, support, tout a commencé ici.&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Jacques Disner&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Traduction française&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;XanK&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Traduction espagnole&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Giannis Antoniou&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;; font-size:10pt;&quot;&gt;Traduction grecque&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <source>&lt;!DOCTYPE HTML PUBLIC &quot;-//W3C//DTD HTML 4.0//EN&quot; &quot;http://www.w3.org/TR/REC-html40/strict.dtd&quot;&gt;
&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Shaman 1.0 Beta (revision 651)&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;!DOCTYPE HTML PUBLIC &quot;-//W3C//DTD HTML 4.0//EN&quot; &quot;http://www.w3.org/TR/REC-html40/strict.dtd&quot;&gt;
&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Bitstream Vera Sans&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Shaman 1.0 Beta (修訂版 651)&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <source>&lt;!DOCTYPE HTML PUBLIC &quot;-//W3C//DTD HTML 4.0//EN&quot; &quot;http://www.w3.org/TR/REC-html40/strict.dtd&quot;&gt;
&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;&quot;&gt;&lt;span style=&quot; font-size:10pt;&quot;&gt;Shaman has received a lot of help from a lot of people, and it is also thanks to them if Shaman has seen the light. If we forgot to add you here, let us know.&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Names are in alphabetical order, because even the smallest contribution has been important to us.&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;The KDEMod Community&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;Help, Testing, Support, everything started from here. If there was no KDEMod, probably&lt;/span&gt; &lt;span style=&quot; font-weight:400;&quot;&gt;there would be no Shaman&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Giannis Antoniou&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Greek Translator&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Carlos Berroteran&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Spanish Translator&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Jacques Disner&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;French Translator&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Georg Grabler&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;Author of the Proxy patch, some help on the code and more.&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Michael Knights&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Artwork creator, his icon proposal lies now in Arxin, but his splashscreen is in here ;)&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Till Luge&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;Heavy tester, thanks!&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Rodrigo Mazak&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Brazilian Translator, and gave the name Shaman&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;Jan Mette&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;German Translation and KDEMod-Developer, also the creator of the Icon&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Atilla Ontas&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Turkish Translator&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Martin Sandsmark&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Our hoster, and maintainer of Trac.&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Johannes Schriewer&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;KDEMod Developer, and also some help on the code.&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;!DOCTYPE HTML PUBLIC &quot;-//W3C//DTD HTML 4.0//EN&quot; &quot;http://www.w3.org/TR/REC-html40/strict.dtd&quot;&gt;
&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;&quot;&gt;&lt;span style=&quot; font-size:10pt;&quot;&gt;Shaman 獲得許多人的幫助，如果 Shaman 眾所皆知也該感謝這些付出的人。 如果我們忘了將你的名字加到這裡，請通知我們。&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;名字按字母順序排列，因為即使極小的貢獻也對我們很重要。&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;KDEMod 社群&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;幫忙、測試、支援，一切的起源。 如果沒有 KDEmod，可能&lt;/span&gt; &lt;span style=&quot; font-weight:400;&quot;&gt;也不會有 Shaman&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Giannis Antoniou&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;希臘文翻譯者&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Carlos Berroteran&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;西班牙語翻譯者&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Jacques Disner&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;法文翻譯者&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Georg Grabler&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;代理修補的作者，在代碼與其他方面給予一些幫助。&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Michael Knights&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;美工創作者，他的圖示方案被用在 Arxin，但他的啟動畫面被用在這裡 ;)&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Till Luge&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;重量級測試人員，感謝！&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Rodrigo Mazak&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;巴西翻譯者，並給予 Shaman 這個名稱&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;Jan Mette&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;德語翻譯兼 KDEmod 開發者也是圖示的創作者&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Atilla Ontas&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;土耳其語翻譯者&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Martin Sandsmark&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;我們主機維護者兼 Trac 的維護人員。&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Johannes Schriewer&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;KDEmod 開發者，也在代碼上給予一些幫助。&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <source>Visit &amp;Website...</source>
        <translation>訪問網站(&amp;W)...</translation>
    </message>
    <message>
        <source>&lt;!DOCTYPE HTML PUBLIC &quot;-//W3C//DTD HTML 4.0//EN&quot; &quot;http://www.w3.org/TR/REC-html40/strict.dtd&quot;&gt;
&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Shaman 1.0 Beta (revision 721)&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;!DOCTYPE HTML PUBLIC &quot;-//W3C//DTD HTML 4.0//EN&quot; &quot;http://www.w3.org/TR/REC-html40/strict.dtd&quot;&gt;
&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Bitstream Vera Sans&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Shaman 1.0 Beta (修訂版 721)&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <source>&lt;!DOCTYPE HTML PUBLIC &quot;-//W3C//DTD HTML 4.0//EN&quot; &quot;http://www.w3.org/TR/REC-html40/strict.dtd&quot;&gt;
&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;&quot;&gt;&lt;span style=&quot; font-size:10pt;&quot;&gt;Shaman has received a lot of help from a lot of people, and it is also thanks to them if Shaman has seen the light. If we forgot to add you here, let us know.&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Names are in alphabetical order, because even the smallest contribution has been important to us.&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;The KDEmod Community&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;Help, Testing, Support, everything started from here. If there was no KDEmod, probably&lt;/span&gt; &lt;span style=&quot; font-weight:400;&quot;&gt;there would be no Shaman&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Giannis Antoniou&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Greek Translator&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Carlos Berroteran&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Spanish Translator&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Jacques Disner&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;French Translator&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Stefano Giro&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;Testing and Suggestions&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Georg Grabler&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;Author of the Proxy patch, some help on the code and more.&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Michael Knights&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Artwork creator, his icon proposal lies now in Arxin, but his splashscreen is in here ;)&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Till Luge&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;Heavy tester, thanks!&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Rodrigo Mazak&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Brazilian Translator, and gave the name Shaman&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;Jan Mette&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;German Translation and KDEmod Developer, also the creator of the Icon&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Atilla Ontas&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Turkish Translator&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Martin Sandsmark&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Our hoster, and maintainer of Trac.&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Johannes Schriewer&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;KDEmod Developer, and also some help on the code.&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Xiang Yixiang&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Chinese Translator&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;!DOCTYPE HTML PUBLIC &quot;-//W3C//DTD HTML 4.0//EN&quot; &quot;http://www.w3.org/TR/REC-html40/strict.dtd&quot;&gt;
&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;&quot;&gt;&lt;span style=&quot; font-size:10pt;&quot;&gt;Shaman 獲得許多人的幫助，如果 Shaman 眾所皆知也該感謝這些付出的人。 如果我們忘了將你的名字加到這裡，請通知我們。&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;名字按字母順序排列，因為即使極小的貢獻也對我們很重要。&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;KDEmod 社群&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;幫忙、測試、支援，一切的起源。 如果沒有 KDEmod，可能&lt;/span&gt; &lt;span style=&quot; font-weight:400;&quot;&gt;也不會有 Shaman&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Giannis Antoniou&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;希臘文翻譯者&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Carlos Berroteran&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;西班牙語翻譯者&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Jacques Disner&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;法文翻譯者&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Stefano Giro&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;測試和建議&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Georg Grabler&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;代理修補的作者，在代碼與其他方面給予一些幫助。&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Michael Knights&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;美工創作者，他的圖示方案被用在 Arxin，但他的啟動畫面被用在這裡 ;)&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Till Luge&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;重量級測試人員，感謝！&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Rodrigo Mazak&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;巴西翻譯者，並給予 Shaman 這個名稱&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;Jan Mette&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;德語翻譯兼 KDEmod 開發者也是圖示的創作者&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Atilla Ontas&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;土耳其語翻譯者&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Martin Sandsmark&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;我們主機維護者兼 Trac 的維護人員。&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Johannes Schriewer&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;KDEmod 開發者，也在代碼上給予一些幫助。&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Xiang Yixiang&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;簡體中文翻譯者&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <source>&lt;!DOCTYPE HTML PUBLIC &quot;-//W3C//DTD HTML 4.0//EN&quot; &quot;http://www.w3.org/TR/REC-html40/strict.dtd&quot;&gt;
&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;&quot;&gt;&lt;span style=&quot; font-size:10pt;&quot;&gt;Shaman has received a lot of help from a lot of people, and it is also thanks to them if Shaman has seen the light. If we forgot to add you here, let us know.&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Names are in alphabetical order, because even the smallest contribution has been important to us.&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;The KDEmod Community&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;Help, Testing, Support, everything started from here. If there was no KDEmod, probably&lt;/span&gt; &lt;span style=&quot; font-weight:400;&quot;&gt;there would be no Shaman&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Giannis Antoniou&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Greek Translator&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Carlos Berroteran&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Spanish Translator&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Sander De Voogdt&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Dutch Translator&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Jacques Disner&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;French Translator&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Jan Dupal&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Czech Translator&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Stefano Giro&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;Testing and Suggestions&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Georg Grabler&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;Author of the Proxy patch, some help on the code and more.&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Michael Knights&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Artwork creator, his icon proposal lies now in Arxin, but his splashscreen is in here ;)&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Till Luge&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;Heavy tester, thanks!&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Rodrigo Mazak&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Brazilian Translator, and gave the name Shaman&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;Jan Mette&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;German Translation and KDEmod Developer, also the creator of the Icon&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Atilla Ontas&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Turkish Translator&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Martin Sandsmark&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Our hoster, and maintainer of Trac.&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Johannes Schriewer&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;KDEmod Developer, and also some help on the code.&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Xiang Yixiang&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Chinese Translator&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Anton Gritsay&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Russian Translator and Patches related to Translations&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;!DOCTYPE HTML PUBLIC &quot;-//W3C//DTD HTML 4.0//EN&quot; &quot;http://www.w3.org/TR/REC-html40/strict.dtd&quot;&gt;
&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;&quot;&gt;&lt;span style=&quot; font-size:10pt;&quot;&gt;Shaman 獲得許多人的幫助，如果 Shaman 眾所皆知也該感謝這些付出的人。 如果我們忘了將你的名字加到這裡，請通知我們。&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;名字按字母順序排列，因為即使極小的貢獻也對我們很重要。&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;KDEmod 社群&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;幫忙、測試、支援，一切的起源。 如果沒有 KDEmod，可能&lt;/span&gt; &lt;span style=&quot; font-weight:400;&quot;&gt;也不會有 Shaman&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Giannis Antoniou&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;希臘文翻譯者&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Carlos Berroteran&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;西班牙語翻譯者&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Jacques Disner&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;法文翻譯者&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Stefano Giro&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;測試和建議&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Georg Grabler&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;代理修補的作者，在代碼與其他方面給予一些幫助。&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Michael Knights&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;美工創作者，他的圖示方案被用在 Arxin，但他的啟動畫面被用在這裡 ;)&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Till Luge&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;重量級測試人員，感謝！&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Rodrigo Mazak&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;巴西翻譯者，並給予 Shaman 這個名稱&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;Jan Mette&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;德語翻譯兼 KDEmod 開發者也是圖示的創作者&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Atilla Ontas&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;土耳其語翻譯者&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Martin Sandsmark&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;我們主機維護者兼 Trac 的維護人員。&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Johannes Schriewer&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;KDEmod 開發者，也在代碼上給予一些幫助。&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Xiang Yixiang&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;簡體中文翻譯者&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Anton Gritsay&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;俄語翻譯者兼翻譯相關的修補&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <source>&lt;!DOCTYPE HTML PUBLIC &quot;-//W3C//DTD HTML 4.0//EN&quot; &quot;http://www.w3.org/TR/REC-html40/strict.dtd&quot;&gt;
&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;&quot;&gt;&lt;span style=&quot; font-size:10pt;&quot;&gt;Shaman has received a lot of help from a lot of people, and it is also thanks to them if Shaman has seen the light. If we forgot to add you here, let us know.&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Names are in alphabetical order, because even the smallest contribution has been important to us.&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;The KDEmod Community&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;Help, Testing, Support, everything started from here. If there was no KDEmod, probably&lt;/span&gt; &lt;span style=&quot; font-weight:400;&quot;&gt;there would be no Shaman&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Giannis Antoniou&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Greek Translator&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Carlos Berroteran&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Spanish Translator&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Sander De Voogdt&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Dutch Translator&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Jacques Disner&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;French Translator&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Jan Dupal&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Czech Translator&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Stefano Giro&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;Testing and Suggestions&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Georg Grabler&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;Author of the Proxy patch, some help on the code and more.&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Michael Knights&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Artwork creator, his icon proposal lies now in Arxin, but his splashscreen is in here ;)&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Till Luge&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;Heavy tester, thanks!&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Rodrigo Mazak&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Brazilian Translator, and gave the name Shaman&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;Jan Mette&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;German Translation and KDEmod Developer, also the creator of the Icon&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Atilla Ontas&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Turkish Translator&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Martin Sandsmark&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Our hoster, and maintainer of Trac.&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Johannes Schriewer&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;KDEmod Developer, and also some help on the code.&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Xiang Yixiang&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Chinese Translator&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Anton Gritsay&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Russian Translator and Patches related to Translations&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Bartek Iwaniec&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;Polish Translator&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Marko Doda&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;Macedonian Translator&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;!DOCTYPE HTML PUBLIC &quot;-//W3C//DTD HTML 4.0//EN&quot; &quot;http://www.w3.org/TR/REC-html40/strict.dtd&quot;&gt;
&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;&quot;&gt;&lt;span style=&quot; font-size:10pt;&quot;&gt;Shaman 獲得許多人的幫助，如果 Shaman 眾所皆知也該感謝這些付出的人。 如果我們忘了將你的名字加到這裡，請通知我們。&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;名字按字母順序排列，因為即使極小的貢獻也對我們很重要。&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;KDEmod 社群&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;幫忙、測試、支援，一切的起源。 如果沒有 KDEmod，可能&lt;/span&gt; &lt;span style=&quot; font-weight:400;&quot;&gt;也不會有 Shaman&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Giannis Antoniou&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;希臘文翻譯者&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Carlos Berroteran&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;西班牙語翻譯者&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Sander De Voogdt&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;荷蘭語翻譯者&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Jacques Disner&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;法文翻譯者&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Jan Dupal&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;捷克語翻譯者&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Stefano Giro&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;測試和建議&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Georg Grabler&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;代理修補的作者，在代碼與其他方面給予一些幫助。&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Michael Knights&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;美工創作者，他的圖示方案被用在 Arxin，但他的啟動畫面被用在這裡 ;)&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Till Luge&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;重量級測試人員，感謝！&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Rodrigo Mazak&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;巴西翻譯者，並給予 Shaman 這個名稱&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;Jan Mette&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;德語翻譯兼 KDEmod 開發者也是圖示的創作者&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Atilla Ontas&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;土耳其語翻譯者&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Martin Sandsmark&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;我們主機維護者兼 Trac 的維護人員。&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Johannes Schriewer&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;KDEmod 開發者，也在代碼上給予一些幫助。&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Xiang Yixiang&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;簡體中文翻譯者&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Anton Gritsay&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;俄語翻譯者兼翻譯相關的修補&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Bartek Iwaniec&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;波蘭語翻譯者&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Marko Doda&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;馬其頓人語翻譯者&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
</context>
<context>
    <name>authDialog</name>
    <message>
        <source>Root Password Required</source>
        <translation>需要 root 密碼</translation>
    </message>
    <message>
        <source>Shaman needs root privileges to perform this action.
Please enter in the field below the root password to continue.</source>
        <translation>Shaman 需要 root 權限執行這個動作。
請在下面的地方輸入 root 密碼以繼續進行。</translation>
    </message>
    <message>
        <source>Never ask for this anymore</source>
        <translation>以後不再詢問</translation>
    </message>
    <message>
        <source>Cancel</source>
        <translation>取消</translation>
    </message>
    <message>
        <source>Backspace</source>
        <translation>倒退鍵</translation>
    </message>
    <message>
        <source>Ok</source>
        <translation>確定</translation>
    </message>
    <message>
        <source>Return</source>
        <translation>返回</translation>
    </message>
</context>
<context>
    <name>buildingDialog</name>
    <message>
        <source>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Liberation Sans&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Building Packages...&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Liberation Sans&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;正在編譯套件...&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <source>Abort</source>
        <translation>中止</translation>
    </message>
    <message>
        <source>Reduce To Tray</source>
        <translation>縮至收藏匣</translation>
    </message>
    <message>
        <source>Shaman - Building Packages</source>
        <translation>Shaman - 正在編譯套件</translation>
    </message>
</context>
<context>
    <name>dbUpdateDialog</name>
    <message>
        <source>Database Update</source>
        <translation>資料庫更新</translation>
    </message>
    <message>
        <source>Update Database..</source>
        <translation>更新資料庫..</translation>
    </message>
</context>
<context>
    <name>editPBDialog</name>
    <message>
        <source>Editing PKGBUILD</source>
        <translation>編輯 PKGBUILD</translation>
    </message>
    <message>
        <source>Editing PKGBUILD of:</source>
        <translation>編輯 PKGBUILD:</translation>
    </message>
    <message>
        <source>Save</source>
        <translation>儲存</translation>
    </message>
    <message>
        <source>Undo</source>
        <translation>回復</translation>
    </message>
    <message>
        <source>Redo</source>
        <translation>重做</translation>
    </message>
    <message>
        <source>Ok</source>
        <translation>確定</translation>
    </message>
    <message>
        <source>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Edit PKGBUILD&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;編輯 PKGBUILD&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
</context>
<context>
    <name>logViewer</name>
    <message>
        <source>Shaman - Log Viewer</source>
        <translation>Shaman - 日誌檢視器</translation>
    </message>
    <message>
        <source>Show Only Logs From</source>
        <translation>只顯示日誌從</translation>
    </message>
    <message>
        <source>Show Only Logs Until</source>
        <translation>只顯示日誌到</translation>
    </message>
    <message>
        <source>Filter</source>
        <translation>篩選器</translation>
    </message>
    <message>
        <source>Refresh View</source>
        <translation>重新整理檢視</translation>
    </message>
    <message>
        <source>Close</source>
        <translation>關閉</translation>
    </message>
    <message>
        <source>&lt;!DOCTYPE HTML PUBLIC &quot;-//W3C//DTD HTML 4.0//EN&quot; &quot;http://www.w3.org/TR/REC-html40/strict.dtd&quot;&gt;
&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Liberation Sans&apos;; font-size:9pt;&quot;&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;!DOCTYPE HTML PUBLIC &quot;-//W3C//DTD HTML 4.0//EN&quot; &quot;http://www.w3.org/TR/REC-html40/strict.dtd&quot;&gt;
&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Liberation Sans&apos;; font-size:9pt;&quot;&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <source>dd/MM/yyyy</source>
        <translation>dd/MM/yyyy</translation>
    </message>
</context>
<context>
    <name>newsDialog</name>
    <message>
        <source>Arch Linux News</source>
        <translation>Arch Linux 新聞</translation>
    </message>
    <message>
        <source>Link</source>
        <translation>連結</translation>
    </message>
    <message>
        <source>status</source>
        <translation>狀態</translation>
    </message>
    <message>
        <source>Mark as Read</source>
        <translation>標記為已閱讀</translation>
    </message>
    <message>
        <source>Open in Browser</source>
        <translation>用瀏覽器開啟</translation>
    </message>
    <message>
        <source>Refresh</source>
        <translation>重新整理</translation>
    </message>
    <message>
        <source>Close</source>
        <translation>關閉</translation>
    </message>
    <message>
        <source>News-Title</source>
        <translation>新聞-標題</translation>
    </message>
</context>
<context>
    <name>pkgProperties</name>
    <message>
        <source>&lt;!DOCTYPE HTML PUBLIC &quot;-//W3C//DTD HTML 4.0//EN&quot; &quot;http://www.w3.org/TR/REC-html40/strict.dtd&quot;&gt;
&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Bitstream Vera Sans&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Package Information&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;!DOCTYPE HTML PUBLIC &quot;-//W3C//DTD HTML 4.0//EN&quot; &quot;http://www.w3.org/TR/REC-html40/strict.dtd&quot;&gt;
&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Bitstream Vera Sans&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;套件資訊&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <source>Package Information</source>
        <translation>套件資訊</translation>
    </message>
    <message>
        <source>Installed:</source>
        <translation>已安裝:</translation>
    </message>
    <message>
        <source>Description:</source>
        <translation>描述:</translation>
    </message>
    <message>
        <source>Upgradeable</source>
        <translation>可升級</translation>
    </message>
    <message>
        <source>Build Date:</source>
        <translation>編譯日期:</translation>
    </message>
    <message>
        <source>Provides:</source>
        <translation>提供:</translation>
    </message>
    <message>
        <source>Install Date:</source>
        <translation>安裝日期:</translation>
    </message>
    <message>
        <source>Packager:</source>
        <translation>套件建立者:</translation>
    </message>
    <message>
        <source>Size:</source>
        <translation>大小:</translation>
    </message>
    <message>
        <source>Has a Scriptlet</source>
        <translation>含有程式敘述</translation>
    </message>
    <message>
        <source>Version:</source>
        <translation>版本:</translation>
    </message>
    <message>
        <source>Changelog</source>
        <translation>變更日誌</translation>
    </message>
    <message>
        <source>Files</source>
        <translation>檔案</translation>
    </message>
    <message>
        <source>1</source>
        <translation>1</translation>
    </message>
    <message>
        <source>Dependencies</source>
        <translation>相依套件</translation>
    </message>
    <message>
        <source>Depends on</source>
        <translation>相依於</translation>
    </message>
    <message>
        <source>Is Required by</source>
        <translation>需要它的套件</translation>
    </message>
    <message>
        <source>Actions Performed</source>
        <translation>已執行的動作</translation>
    </message>
    <message>
        <source>Ok</source>
        <translation>確定</translation>
    </message>
</context>
<context>
    <name>reviewBuildingDialog</name>
    <message>
        <source>Review Building Queue</source>
        <translation>重新檢視編譯佇列</translation>
    </message>
    <message>
        <source>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Liberation Sans&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Build Queue From Source&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Liberation Sans&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;從原始碼編譯的佇列&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <source>Process All Dependencies from Binary First (advised)</source>
        <translation>先從二進位檔處理所有的相依性 (建議)</translation>
    </message>
    <message>
        <source>This is useful if you want to review compiler&apos;s output</source>
        <translation>如果你想要重新檢視編譯器的輸出，這會很有用</translation>
    </message>
    <message>
        <source>Turn off PC when Queue is done</source>
        <translation>佇列處理結束時關閉電腦</translation>
    </message>
    <message>
        <source>Show packages...</source>
        <translation>顯示套件...</translation>
    </message>
    <message>
        <source>Packages In Queue</source>
        <translation>佇列中的套件</translation>
    </message>
    <message>
        <source>Abort</source>
        <translation>中止</translation>
    </message>
    <message>
        <source>Process From Binary</source>
        <translation>從二位元檔處理</translation>
    </message>
    <message>
        <source>Review PKGBUILDs</source>
        <translation>檢查 PKGBUILD</translation>
    </message>
    <message>
        <source>Process From Source</source>
        <translation>從原始碼處理</translation>
    </message>
    <message>
        <source>Do not install immediately when building is finished</source>
        <translation>當編譯完成時不要直接安裝</translation>
    </message>
</context>
<context>
    <name>transactionDialog</name>
    <message>
        <source>Processing Queue...</source>
        <translation>正在處理佇列...</translation>
    </message>
    <message>
        <source>Check transaction validity</source>
        <translation>檢查執行項目正確性</translation>
    </message>
    <message>
        <source>Download Packages</source>
        <translation>下載套件</translation>
    </message>
    <message>
        <source>Process queue</source>
        <translation>處理佇列</translation>
    </message>
    <message>
        <source>Cleanup</source>
        <translation>清理</translation>
    </message>
    <message>
        <source>More Details...</source>
        <translation>更多細節...</translation>
    </message>
    <message>
        <source>Abort</source>
        <translation>中止</translation>
    </message>
    <message>
        <source>Please Wait...</source>
        <translation>請稍等...</translation>
    </message>
    <message>
        <source>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Process Queue&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;處理佇列&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
</context>
<context>
    <name>upgradeDialog</name>
    <message>
        <source>System Upgrade</source>
        <translation>系統升級</translation>
    </message>
    <message>
        <source>Remember my choice</source>
        <translation>記住我的選擇</translation>
    </message>
    <message>
        <source>Abort</source>
        <translation>中止</translation>
    </message>
    <message>
        <source>Add to Queue</source>
        <translation>加到佇列</translation>
    </message>
    <message>
        <source>Upgrade Now</source>
        <translation>立刻升級</translation>
    </message>
    <message>
        <source>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;System-Upgrade&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;系統升級&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <source>Packages to Upgrade</source>
        <translation>套件進行升級</translation>
    </message>
    <message>
        <source>Show packages...</source>
        <translation>顯示套件...</translation>
    </message>
    <message>
        <source>Force Queue Processing</source>
        <translation>強制處理佇列</translation>
    </message>
</context>
</TS>
