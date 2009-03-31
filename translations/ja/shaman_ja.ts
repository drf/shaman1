<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.0" language="ja_JP">
<context>
    <name>BuildingDialog</name>
    <message>
        <location filename="../src/BuildingDialog.cpp" line="52"/>
        <source>Error</source>
        <translation>エラー</translation>
    </message>
    <message>
        <location filename="../src/BuildingDialog.cpp" line="52"/>
        <source>Would you like to abort building?.
All Process will be lost.</source>
        <translation>ビルド作業を中止しますか?
この時、作業中のデータは失われます。</translation>
    </message>
    <message>
        <location filename="../src/BuildingDialog.cpp" line="62"/>
        <source>&lt;br&gt;&lt;br&gt;&lt;b&gt;Building Process Aborted by the User. Building Failed.&lt;/b&gt;</source>
        <translation>&lt;br&gt;&lt;br&gt;&lt;b&gt;ビルド作業はユーザーによって中止されました。ビルド作業は失敗です。&lt;/b&gt;</translation>
    </message>
    <message>
        <location filename="../src/BuildingDialog.cpp" line="197"/>
        <source>&lt;br&gt;&lt;br&gt;&lt;b&gt;ABS Tree Was Successfully Updated!&lt;/b&gt;</source>
        <translation>&lt;br&gt;&lt;br&gt;&lt;b&gt;ABSディレクトリ構造は正常に更新されました。&lt;/b&gt;</translation>
    </message>
    <message>
        <location filename="../src/BuildingDialog.cpp" line="199"/>
        <location filename="../src/BuildingDialog.cpp" line="204"/>
        <source>ABS Update</source>
        <translation>ABSアップデート</translation>
    </message>
    <message>
        <location filename="../src/BuildingDialog.cpp" line="199"/>
        <source>Your ABS Tree was updated!</source>
        <translation>あなたのABSディレクトリ構造は更新されました!</translation>
    </message>
    <message>
        <location filename="../src/BuildingDialog.cpp" line="202"/>
        <location filename="../src/BuildingDialog.cpp" line="204"/>
        <source>Could not update the ABS Tree!</source>
        <translation>ABSディレクトリ構造を更新できません!</translation>
    </message>
    <message>
        <location filename="../src/BuildingDialog.cpp" line="217"/>
        <source>&lt;b&gt;Building %1 failed!!&lt;/b&gt;&lt;br&gt;&lt;br&gt;</source>
        <translation>&lt;b&gt;%1のビルドに失敗しました!&lt;/b&gt;&lt;br&gt;&lt;br&gt;</translation>
    </message>
    <message>
        <location filename="../src/BuildingDialog.cpp" line="220"/>
        <source>&lt;b&gt;%1 was built successfully!!&lt;/b&gt;&lt;br&gt;&lt;br&gt;</source>
        <translation>&lt;b&gt;%1のビルドに成功しました!&lt;/b&gt;&lt;br&gt;&lt;br&gt;</translation>
    </message>
    <message>
        <location filename="../src/BuildingDialog.cpp" line="272"/>
        <source>Processing Package %1 of %2...</source>
        <translation>パッケージを処理しています。 %1/%2...</translation>
    </message>
    <message>
        <location filename="../src/BuildingDialog.cpp" line="273"/>
        <source>Building %1...</source>
        <translation>ビルド中 %1...</translation>
    </message>
    <message>
        <location filename="../src/BuildingDialog.cpp" line="278"/>
        <source>&lt;b&gt;Could not set up the environment correctly for %1!!&lt;/b&gt;&lt;br&gt;&lt;br&gt;</source>
        <translation>&lt;b&gt;%1のための環境をセットアップできませんでした。&lt;/b&gt;&lt;br&gt;&lt;br&gt;</translation>
    </message>
    <message>
        <location filename="../src/BuildingDialog.cpp" line="300"/>
        <source>&lt;b&gt;Building %1...&lt;/b&gt;&lt;br&gt;&lt;br&gt;</source>
        <translation>&lt;b&gt;ビルド中 %1...&lt;/b&gt;&lt;br&gt;&lt;br&gt;</translation>
    </message>
    <message>
        <location filename="../src/BuildingDialog.cpp" line="325"/>
        <source>&lt;b&gt;Building operation has started.&lt;/b&gt;&lt;br&gt;&lt;br&gt;</source>
        <translation>&lt;b&gt;ビルド作業を開始します。&lt;/b&gt;&lt;br&gt;&lt;br&gt;</translation>
    </message>
</context>
<context>
    <name>BuildingHandler</name>
    <message>
        <location filename="../src/BuildingHandler.cpp" line="53"/>
        <location filename="../src/BuildingHandler.cpp" line="86"/>
        <location filename="../src/BuildingHandler.cpp" line="112"/>
        <location filename="../src/BuildingHandler.cpp" line="122"/>
        <location filename="../src/BuildingHandler.cpp" line="275"/>
        <location filename="../src/BuildingHandler.cpp" line="289"/>
        <source>Error</source>
        <translation>エラー</translation>
    </message>
    <message>
        <location filename="../src/BuildingHandler.cpp" line="53"/>
        <location filename="../src/BuildingHandler.cpp" line="86"/>
        <source>You need to have ABS installed to use Shaman&apos;s
building feature. Do you want to install it now?</source>
        <translation>Shamanのビルド機能の使用にはABS(The Arch Build System)をインストールする必要があります。
今すぐインストールしますか?</translation>
    </message>
    <message>
        <location filename="../src/BuildingHandler.cpp" line="112"/>
        <source>You can not remove packages when processing
your queue from Source</source>
        <translation>供給元からのキューを処理している間、パッケージを削除することはできません</translation>
    </message>
    <message>
        <location filename="../src/BuildingHandler.cpp" line="122"/>
        <source>Some of your packages do not belong to Arch
Linux&apos;s official repository. Shaman is able to
build packages from official sources only.</source>
        <translation>いくつかのパッケージはArch Linuxの公式リポジトリには含まれていません。
Shamanは正式な供給元からのみパッケージをビルドできます。</translation>
    </message>
    <message numerus="yes">
        <location filename="../src/BuildingHandler.cpp" line="156"/>
        <source>You are about to install &lt;b&gt;%n package(s)&lt;/b&gt; from source. Building from source&lt;br&gt;can give some advantages, however is very slow.&lt;br&gt;If you are not sure about that, you would probably prefer to process&lt;br&gt;your queue from binary files. Before you continue, you are advised to&lt;br&gt;review your configuration to improve your building performance.</source>
        <translation>
            <numerusform>貴方は今、提供元から&lt;b&gt;%n個のパッケージ&lt;/b&gt;をインストールしようとしています。&lt;br&gt;ソースからのビルドは幾つかの利点がありますが、&lt;b&gt;非常に遅い&lt;/b&gt;です。&lt;br&gt;この事について確信がないのなら、バイナリファイルからのインストールを選んでください。
作業を続ける前に、ビルドパフォーマンス改善の為の設定を慎重に確認してください。</numerusform>
        </translation>
    </message>
    <message>
        <location filename="../src/BuildingHandler.cpp" line="164"/>
        <location filename="../src/BuildingHandler.cpp" line="175"/>
        <source>To be Installed</source>
        <translation>インストール済み</translation>
    </message>
    <message>
        <location filename="../src/BuildingHandler.cpp" line="168"/>
        <location filename="../src/BuildingHandler.cpp" line="181"/>
        <source>To be Upgraded</source>
        <translation>アップグレード済み</translation>
    </message>
    <message>
        <location filename="../src/BuildingHandler.cpp" line="273"/>
        <location filename="../src/BuildingHandler.cpp" line="314"/>
        <source>Package Building</source>
        <translation>パッケージビルド</translation>
    </message>
    <message>
        <location filename="../src/BuildingHandler.cpp" line="273"/>
        <source>Your Packages failed to build!</source>
        <translation>パッケージのビルドに失敗しました!</translation>
    </message>
    <message>
        <location filename="../src/BuildingHandler.cpp" line="275"/>
        <source>Your packages Failed to Build.
Look at the output for more details.</source>
        <translation>パッケージのビルドに失敗しました。
出力を確認して詳細をご覧ください。</translation>
    </message>
    <message>
        <location filename="../src/BuildingHandler.cpp" line="278"/>
        <location filename="../src/BuildingHandler.cpp" line="295"/>
        <source>Close</source>
        <translation>閉じる</translation>
    </message>
    <message>
        <location filename="../src/BuildingHandler.cpp" line="281"/>
        <location filename="../src/BuildingHandler.cpp" line="286"/>
        <source>Building Packages Failed!!</source>
        <translation>パッケージ群のビルドに失敗しました!!</translation>
    </message>
    <message>
        <location filename="../src/BuildingHandler.cpp" line="290"/>
        <source>Some packages failed to build.
Do you want to proceed anyway?</source>
        <translation>幾つかのパッケージのビルドに失敗しました。
それでも作業を続行しますか?</translation>
    </message>
    <message>
        <location filename="../src/BuildingHandler.cpp" line="309"/>
        <source>Install Built Packages</source>
        <translation>ビルドパッケージのインストール</translation>
    </message>
    <message>
        <location filename="../src/BuildingHandler.cpp" line="310"/>
        <source>Close Without Installing</source>
        <translation>インストールせずに閉じる</translation>
    </message>
    <message>
        <location filename="../src/BuildingHandler.cpp" line="311"/>
        <source>Packages Built Successfully!</source>
        <translation>パッケージのビルドに成功しました!</translation>
    </message>
    <message>
        <location filename="../src/BuildingHandler.cpp" line="314"/>
        <source>Your Packages have been built successfully, and are ready to be installed</source>
        <translation>パッケージのビルドに成功し、インストールの準備が整いました</translation>
    </message>
</context>
<context>
    <name>ConfigDialog</name>
    <message>
        <location filename="../src/configDialog.cpp" line="118"/>
        <source>General</source>
        <translation>一般</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="120"/>
        <location filename="../src/configDialog.cpp" line="606"/>
        <source>Clean Unused Databases</source>
        <translation>使われていないデータベースを消去</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="120"/>
        <location filename="../src/configDialog.cpp" line="616"/>
        <source>Clean Cache</source>
        <translation>キャッシュの消去</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="121"/>
        <location filename="../src/configDialog.cpp" line="626"/>
        <source>Empty Cache</source>
        <translation>空のキャッシュ</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="121"/>
        <location filename="../src/configDialog.cpp" line="636"/>
        <source>Optimize Pacman Database</source>
        <translation>Pacmanデータベースの最適化</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="121"/>
        <location filename="../src/configDialog.cpp" line="649"/>
        <source>Clean All Building Environments</source>
        <translation>全てのビルド環境を消去</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="179"/>
        <source>Repositories</source>
        <translation>リポジトリ</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="303"/>
        <source>Pacman</source>
        <translation>Pacman</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="370"/>
        <source>ABS</source>
        <translation>ABS</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="411"/>
        <source>Advanced</source>
        <translation>上級者向け</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="498"/>
        <location filename="../src/configDialog.cpp" line="545"/>
        <source>Enter Here the Repository&apos;s Name</source>
        <translation>リポジトリ名を入力</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="500"/>
        <location filename="../src/configDialog.cpp" line="547"/>
        <source>Enter Here the Repository&apos;s Server</source>
        <translation>リポジトリ・サーバを入力</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="507"/>
        <location filename="../src/configDialog.cpp" line="554"/>
        <location filename="../ui/configDialog.ui" line="1238"/>
        <source>Ok</source>
        <translation>OK</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="509"/>
        <location filename="../src/configDialog.cpp" line="556"/>
        <location filename="../ui/configDialog.ui" line="1255"/>
        <source>Cancel</source>
        <translation>キャンセル</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="609"/>
        <location filename="../src/configDialog.cpp" line="610"/>
        <source>Cleaning up unused Databases...</source>
        <translation>使われていないデータベースをクリーンアップしています...</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="619"/>
        <location filename="../src/configDialog.cpp" line="620"/>
        <source>Cleaning up Cache...</source>
        <translation>キャッシュをクリーンアップしています...</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="629"/>
        <location filename="../src/configDialog.cpp" line="630"/>
        <source>Deleting Cache...</source>
        <translation>キャッシュを削除しています...</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="652"/>
        <location filename="../src/configDialog.cpp" line="653"/>
        <source>Cleaning up building Environments...</source>
        <translation>ビルド環境をクリーンアップしています...</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="668"/>
        <location filename="../src/configDialog.cpp" line="669"/>
        <source>Cleaning up Unused Databases Failed!</source>
        <translation>使われていないデータベースのクリーンアップに失敗しました!</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="673"/>
        <location filename="../src/configDialog.cpp" line="674"/>
        <source>Cleaning up Cache Failed!</source>
        <translation>キャッシュのクリーンアップに失敗しました!</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="678"/>
        <location filename="../src/configDialog.cpp" line="679"/>
        <source>Deleting Cache Failed!</source>
        <translation>キャッシュのクリーンアップに失敗しました!</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="683"/>
        <location filename="../src/configDialog.cpp" line="684"/>
        <source>Could not clean Build Environments!!</source>
        <translation>ビルド環境のクリーンアップに失敗しました!</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="697"/>
        <location filename="../src/configDialog.cpp" line="698"/>
        <location filename="../src/configDialog.cpp" line="699"/>
        <source>Unused Databases Cleaned up successfully!</source>
        <translation>使われていないデータベースのクリーンアップに成功しました!</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="703"/>
        <location filename="../src/configDialog.cpp" line="704"/>
        <location filename="../src/configDialog.cpp" line="705"/>
        <source>Cache Cleaned Up Successfully!</source>
        <translation>キャッシュのクリーンアップに成功しました!</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="709"/>
        <location filename="../src/configDialog.cpp" line="710"/>
        <location filename="../src/configDialog.cpp" line="711"/>
        <source>Cache Successfully Deleted!</source>
        <translation>キャッシュは正常に削除されました!</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="715"/>
        <location filename="../src/configDialog.cpp" line="716"/>
        <location filename="../src/configDialog.cpp" line="717"/>
        <source>Build Environments Successfully Cleaned!</source>
        <translation>ビルド環境は正常にクリーンされました!</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="762"/>
        <location filename="../src/configDialog.cpp" line="1055"/>
        <source>Saving Configuration</source>
        <translation>設定を保存</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="762"/>
        <source>Unable to save Pacman configuration!</source>
        <translation>Pacmanの設定を保存できません!</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="1055"/>
        <source>Some of your changes have not been applied,
since alpm needs to be released.
You need to restart Shaman to make them effective.</source>
        <translation>alpmのリリースが必要になってから幾つかの変更点が適用されていません。
効果を適用するにはShamanを再起動させる必要があります。</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="1064"/>
        <source>Settings Changed</source>
        <translation>設定が変更されています</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="1065"/>
        <source>Your repositories have changed.
Do you want to Update Your Database?</source>
        <translation>リポジトリが変更されています。
データベースをアップデートしますか?</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="1149"/>
        <location filename="../src/configDialog.cpp" line="1173"/>
        <location filename="../src/configDialog.cpp" line="1190"/>
        <location filename="../src/configDialog.cpp" line="1222"/>
        <location filename="../ui/configDialog.ui" line="536"/>
        <location filename="../ui/configDialog.ui" line="676"/>
        <source>Add Mirror</source>
        <translation>ミラーを追加</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="1149"/>
        <source>Mirror Format is incorrect. Your mirror should look like this:
http://mirror.org/$repo/os/i686</source>
        <comment>Obviously keep the example as it is ;)</comment>
        <translation>ミラーフォーマットが無効です。ミラーのフォーマットは以下のようにする必要があります:
http://mirror.org/$repo/os/i686</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="1174"/>
        <source>Your Mirror was successfully added!
It is now available in mirrorlist.</source>
        <comment>mirrorlist here means /etc/pacman.d/mirrorlist, so it should not be translated.</comment>
        <translation>ミラーは正常に追加されました。
mirrorlistは利用可能です。</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="1190"/>
        <source>Mirror Format is incorrect. Your mirror should look like this:
http://mirror.org/$repo/$arch</source>
        <comment>Obviously keep the example as it is ;)</comment>
        <translation>ミラーフォーマットが無効です。ミラーのフォーマットは以下のようにする必要があります:
http://mirror.org/$repo/$arch</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="1223"/>
        <source>Your Mirror was successfully added!
It is now available in kdemodmirrorlist.</source>
        <comment>mirrorlist here means /etc/pacman.d/kdemodmirrorlist, so it should not be translated.</comment>
        <translation>ミラーは正常に追加されました!
kdemodmirrorlistは利用可能です。</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="1254"/>
        <location filename="../src/configDialog.cpp" line="1255"/>
        <location filename="../src/configDialog.cpp" line="1256"/>
        <source>Pacman Database Optimized Successfully!</source>
        <translation>Pacmanデータベースの最適化に成功しました!</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="1258"/>
        <location filename="../src/configDialog.cpp" line="1259"/>
        <location filename="../src/configDialog.cpp" line="1260"/>
        <source>Could not Optimize Pacman Database!</source>
        <translation>Pacmanデータベースを最適化できませんでした!</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="1267"/>
        <location filename="../src/configDialog.cpp" line="1268"/>
        <source>Running sync...</source>
        <comment>sync is a command, so it should not be translated</comment>
        <translation>syncを起動しています...</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="13"/>
        <source>Shaman - Configuration</source>
        <translation>Shaman - 設定</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="79"/>
        <source>Favourite Actions</source>
        <translation>よく使うアクション</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="88"/>
        <source>When Upgrading System:</source>
        <translation>システムをアップグレードする時:</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="97"/>
        <source>Upgrade Immediately</source>
        <translation>すぐにアップグレードする</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="104"/>
        <source>Add Upgradeable Packages To Queue</source>
        <translation>キューにアップグレードパッケージを追加する</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="111"/>
        <source>Ask</source>
        <translation>確認ダイアログを表示</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="127"/>
        <source>When Processing Queue</source>
        <translation>キューの処理中</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="134"/>
        <source>Keep application running in System Tray only</source>
        <translation>システムトレイにアプリケーションを格納する</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="144"/>
        <source>GUI Startup</source>
        <translation>GUI起動時</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="150"/>
        <source>Start in the System Tray</source>
        <translation>システムトレイ中で開始</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="157"/>
        <source>Show Splashscreen</source>
        <translation>スプラッシュスクリーンを表示</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="164"/>
        <source>Use the following language:</source>
        <translation>使用言語:</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="181"/>
        <source>Disable Tray Icon</source>
        <translation>トレイアイコン無効</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="191"/>
        <source>Maintenance</source>
        <translation>メンテナンス</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="210"/>
        <source>Process Selected</source>
        <translation>選択された項目を実行</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="238"/>
        <source>Waiting</source>
        <comment>Waiting for a user action</comment>
        <translation>待機中</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="256"/>
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
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Liberation Sans&apos;; font-size:9pt;&quot;&gt;Shaman メンテナンス&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Liberation Sans&apos;; font-size:9pt;&quot;&gt;ドロップダウンメニューからアクションを選択してください。&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="283"/>
        <source>Checkable Options</source>
        <translation>チェック可能なオプション</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="289"/>
        <source>Use Active FTP</source>
        <translation>アクティブなFTPを使う</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="296"/>
        <source>Use Deltas (needs xdelta to be installed)</source>
        <translation>差分を使用(xdeltaがインストールされている必要があります。)</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="303"/>
        <source>Use SysLog</source>
        <translation>システムログを使用</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="313"/>
        <source>Advanced Options</source>
        <translation>上級者向けオプション</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="323"/>
        <source>HoldPkgs:</source>
        <translation>保持しているパッケージ:</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="333"/>
        <source>IgnorePkgs:</source>
        <translation>無視するパッケージ:</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="343"/>
        <source>IgnoreGroups:</source>
        <translation>無視するグループ:</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="353"/>
        <source>NoUpgrade:</source>
        <translation>アップグレードしない:</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="363"/>
        <source>NoExtract:</source>
        <translation>解凍しない:</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="373"/>
        <source>Log File:</source>
        <translation>ログファイル:</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="387"/>
        <source>XFerCommand: (example: /path/to/command %u) Blank for Default</source>
        <translation>XFerCommand:(ex:/path/to/command %u) 通常は空にしておいてね</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="425"/>
        <source>Arch Linux Official Repositories</source>
        <translation>Arch Linuxのオフィシャルリポジトリ</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="457"/>
        <source>Here you can choose what repositories to use between Arch Linux&apos;s official ones. Please note that packages from Unstable and Testing may break your system.</source>
        <translation>ここではArch Linuxの公式リポジトリとの間で使うためのリポジトリ群を選択できます。
テスト版・不安定版からのパッケージは貴方のシステムに悪い影響を齎す事に注意して下さい。</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="472"/>
        <source>Core</source>
        <comment>Do not translate</comment>
        <translation>Core</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="479"/>
        <source>Extra</source>
        <comment>Do not translate</comment>
        <translation>Extra</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="486"/>
        <source>Community</source>
        <comment>Do not translate</comment>
        <translation>Community</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="493"/>
        <source>Testing</source>
        <comment>Do not translate</comment>
        <translation>Testing</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="515"/>
        <location filename="../ui/configDialog.ui" line="655"/>
        <location filename="../ui/configDialog.ui" line="732"/>
        <source>Server</source>
        <translation>Server</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="521"/>
        <location filename="../ui/configDialog.ui" line="661"/>
        <source>Mirror:</source>
        <translation>ミラー:</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="555"/>
        <source>KDEMod Repositories</source>
        <translation>KDEModリポジトリ群</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="585"/>
        <source>KDEMod is an improved version of KDE, an Arch Linux exclusive. Featuring an improved Qt build, compatible with Arch Linux standard Qt&apos;s, an improved theme, and lots of addons, KDEMod is the best way to taste the ease and the power of KDE with the simplicity and the power of Arch.</source>
        <translation>KDEModはKDEをArch Linux用に改良したバージョンです。特徴として、Qtビルドの改良、ArchLinuxが提供する標準のQtとの互換性、改良されたテーマ、そして、大量のアドオン群で、KDEModは手軽に、かつ簡単にKDEの力を、そして、Archの力を体験するための最良の手段です。</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="600"/>
        <source>KDEMod 4 Repository</source>
        <translation>KDEMod 4 リポジトリ</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="607"/>
        <source>KDEMod 4 Extragear Repository</source>
        <translation>KDEMod 4 Extragear リポジトリ</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="614"/>
        <source>KDEMod 4 Playground Repository</source>
        <translation>KDEMod 4 Playground リポジトリ</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="621"/>
        <source>KDEMod 4 Testing Repository</source>
        <translation>KDEMod 4 Testing リポジトリ</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="628"/>
        <source>KDEMod 4 Unstable Repository (Testers only!)</source>
        <translation>KDEMod 4 Unstable リポジトリ(注:テスター専用!)</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="635"/>
        <source>KDEMod 3 Repository</source>
        <translation>KDEMod 3 リポジトリ</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="695"/>
        <source>Third-Party Repositories</source>
        <translation>サードパーティーリポジトリ</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="707"/>
        <source>You can extend your packages choice by adding other repositories. Third-Party Repositories act just as normal ones, and will be accessible through both Shaman and Pacman.</source>
        <translation>貴方はパッケージの選択を追加している他のリポジトリへ拡張できます。サードパーティーによるリポジトリは通常のものと同様に振る舞い、また、PacmanとShamanの相互運用を可能にします。</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="727"/>
        <source>Repository</source>
        <translation>リポジトリ</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="755"/>
        <source>Add New Repository</source>
        <translation>新しいリポジトリを追加</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="766"/>
        <source>Edit Repository</source>
        <translation>リポジトリを編集</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="777"/>
        <source>Remove Repository</source>
        <translation>リポジトリを削除</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="800"/>
        <source>Preferences</source>
        <translation>環境設定</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="806"/>
        <source>Process all dependencies and queue from binary first (recommended)</source>
        <translation>全ての依存関係とバイナリからのキューを最初に処理する (推奨)</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="813"/>
        <source>Review Building output before installing</source>
        <translation>インストールを行う前にビルド出力を評価する</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="823"/>
        <source>ABS Configuration</source>
        <translation>ABSの設定</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="829"/>
        <source>Use supfiles that match your current repositories</source>
        <translation>現在のリポジトリ群にマッチするsupfilesを使う</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="836"/>
        <source>Define supfiles manually</source>
        <translation>手動でsupfilesを定義する</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="846"/>
        <source>RSync Server:</source>
        <translation>RSyncサーバー:</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="859"/>
        <source>Makepkg Configuration</source>
        <translation>Makepkgの設定</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="865"/>
        <source>CFlags</source>
        <translation>CFlags</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="875"/>
        <source>CXXFlags</source>
        <translation>CXXFlags</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="885"/>
        <source>BuildEnv</source>
        <translation>BuildEnv</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="895"/>
        <source>Options</source>
        <translation>オプション</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="905"/>
        <source>Doc_Dirs</source>
        <translation>Doc_Dirs</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="918"/>
        <source>Build Environment</source>
        <translation>ビルド環境</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="924"/>
        <source>Building Path</source>
        <translation>ビルドパス</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="934"/>
        <source>Remove installed makedepends after build</source>
        <translation>ビルド後、インストールされたmakedependsを削除する</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="941"/>
        <source>Clean Build Environment after installation</source>
        <translation>インストール後、ビルド環境をクリーンする</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="955"/>
        <source>When Application is in System Tray only</source>
        <translation>アプリケーションがシステムトレイ中にある時</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="961"/>
        <source>Update Database every</source>
        <translation>データベースを次の頻度でアップデートする</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="971"/>
        <location filename="../ui/configDialog.ui" line="1135"/>
        <source>min</source>
        <comment>As in &quot;minutes&quot;</comment>
        <translation>分</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="978"/>
        <source>Show tray notification Windows</source>
        <translation>Windowsのように通知トレイを表示する</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="988"/>
        <source>If upgrades are available:</source>
        <translation>アップグレードが利用可能なら:</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="995"/>
        <source>Just Notify</source>
        <translation>通知するだけ</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="1002"/>
        <source>Notify and add them to Queue</source>
        <translation>通知し、キューに入れる</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="1009"/>
        <source>Update Database at</source>
        <translation>データベースを次の時間にアップデートする</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="1022"/>
        <source>Use a proxy-server</source>
        <translation>プロクシサーバーを使用する</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="1034"/>
        <source>IP:</source>
        <translation>IPアドレス:</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="1057"/>
        <source>Port:</source>
        <translation>ポート番号:</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="1099"/>
        <source>HTTP Proxy</source>
        <translation>HTTPプロクシ</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="1106"/>
        <source>FTP Proxy</source>
        <translation>FTPプロクシ</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="1116"/>
        <source>Use Shaman RSS Capabilities</source>
        <translation>Shaman RSS機能を使う</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="1128"/>
        <source>Update RSS Feed Every</source>
        <translation>次の頻度でRSSフィードをアップデートする</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="1142"/>
        <source>Notify upon new items</source>
        <translation>新しいアイテム上に通知する</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="1149"/>
        <source>Check if there is an unread news about a package in Queue before processing it</source>
        <translation>キューにあるパッケージに関する未読ニュースがあるかどうか作業を行う前にチェックする</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="1185"/>
        <source>Interface</source>
        <translation>インターフェイス</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="1191"/>
        <source>Use Animated Tray Icon</source>
        <translation>アニメーションするトレイアイコンを使用する</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="1198"/>
        <source>Start Shaman Automatically on X Startup</source>
        <translation>X起動時にShamanも自動的に起動する</translation>
    </message>
    <message>
        <location filename="../ui/configDialog.ui" line="1205"/>
        <source>Forbid starting Shaman as root</source>
        <translatorcomment>I wanna know why not recommend starting shaman as root...</translatorcomment>
        <translation>ルートとしてのShamanの起動を禁止する</translation>
    </message>
</context>
<context>
    <name>EditPBuild</name>
    <message>
        <location filename="../src/EditPBuild.cpp" line="58"/>
        <location filename="../src/EditPBuild.cpp" line="141"/>
        <source>Saving</source>
        <translation>保存中</translation>
    </message>
    <message>
        <location filename="../src/EditPBuild.cpp" line="58"/>
        <location filename="../src/EditPBuild.cpp" line="141"/>
        <source>You modified this PKGBUILD.
Do you want to save it?</source>
        <translation>PKGBUILDは変更されています。
保存しますか?</translation>
    </message>
</context>
<context>
    <name>LocalPackage</name>
    <message>
        <location filename="../ui/fromFileDialog.ui" line="13"/>
        <source>Install Package from File</source>
        <translation>ファイルからパッケージをインストール</translation>
    </message>
    <message>
        <location filename="../ui/fromFileDialog.ui" line="38"/>
        <source>&lt;!DOCTYPE HTML PUBLIC &quot;-//W3C//DTD HTML 4.0//EN&quot; &quot;http://www.w3.org/TR/REC-html40/strict.dtd&quot;&gt;
&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Bitstream Vera Sans&apos;;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Local Package Installation&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;!DOCTYPE HTML PUBLIC &quot;-//W3C//DTD HTML 4.0//EN&quot; &quot;http://www.w3.org/TR/REC-html40/strict.dtd&quot;&gt;
&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Bitstream Vera Sans&apos;;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;ローカルパッケージのインストール&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../ui/fromFileDialog.ui" line="151"/>
        <source>Show...</source>
        <translation>表示...</translation>
    </message>
    <message>
        <location filename="../ui/fromFileDialog.ui" line="172"/>
        <source>More Details...</source>
        <translation>詳細...</translation>
    </message>
    <message>
        <location filename="../ui/fromFileDialog.ui" line="196"/>
        <source>Cancel</source>
        <translation>キャンセル</translation>
    </message>
    <message>
        <location filename="../ui/fromFileDialog.ui" line="207"/>
        <source>Install Package</source>
        <translation>パッケージをインストール</translation>
    </message>
</context>
<context>
    <name>LocalPackageDialog</name>
    <message>
        <location filename="../src/LocalPackageDialog.cpp" line="61"/>
        <source>Package is not installed</source>
        <translation>パッケージはインストールされません</translation>
    </message>
    <message>
        <location filename="../src/LocalPackageDialog.cpp" line="64"/>
        <source>Version %1 of this package is already installed</source>
        <translation>バージョン%1のこのパッケージは既にインストールされています</translation>
    </message>
    <message>
        <location filename="../src/LocalPackageDialog.cpp" line="76"/>
        <source>All dependencies are satisfied</source>
        <translation>確定している全ての依存関係</translation>
    </message>
    <message numerus="yes">
        <location filename="../src/LocalPackageDialog.cpp" line="79"/>
        <source>%n package(s) will be installed as dependencies</source>
        <translation>
            <numerusform>%n個のパッケージは依存関係解決の為にインストールされます</numerusform>
        </translation>
    </message>
</context>
<context>
    <name>MainWindow</name>
    <message>
        <location filename="../src/MainWindow.cpp" line="269"/>
        <location filename="../src/MainWindow.cpp" line="613"/>
        <location filename="../ui/MainWindow.ui" line="149"/>
        <source>Name</source>
        <translation>名前</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="270"/>
        <location filename="../src/MainWindow.cpp" line="617"/>
        <location filename="../ui/MainWindow.ui" line="179"/>
        <source>Description</source>
        <translation>説明</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="271"/>
        <location filename="../src/MainWindow.cpp" line="621"/>
        <source>Name and Description</source>
        <translation>名前と説明</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="328"/>
        <source>Ctrl+Q</source>
        <comment>Exit Shaman Shortcut</comment>
        <translation>Ctrl+Q</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="382"/>
        <source>Shaman - Reducing To Tray</source>
        <translation>Shaman - トレイモード</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="383"/>
        <source>Shaman will keep running in the system tray.
To close it, click Quit in the file menu or in the tray icon context menu.
While in the System Tray, Shaman will update your Databases
at a regular interval and notify you about available upgrades.
You can change this behaviour in Settings.</source>
        <translation>Shamanはタスクトレイに常駐します。
之を閉じるには、ファイルメニューから「終了」をクリックするか、トレイアイコンのコンテキストメニューから終了させてください。
システムトレイに常駐している間、Shamanはデータベースを一定間隔でアップデートし、アップグレードがあるなら通知します。
この挙動は設定から変更可能です。</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="481"/>
        <location filename="../ui/MainWindow.ui" line="203"/>
        <source>Repositories</source>
        <translation>リポジトリ</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="488"/>
        <location filename="../src/MainWindow.cpp" line="548"/>
        <location filename="../src/MainWindow.cpp" line="551"/>
        <source>All Repositories</source>
        <translation>全てのリポジトリ</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="500"/>
        <location filename="../src/MainWindow.cpp" line="554"/>
        <source>Local Packages</source>
        <translation>ローカルパッケージ</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="511"/>
        <source>Package Groups</source>
        <translation>パッケージグループ</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="526"/>
        <location filename="../src/MainWindow.cpp" line="549"/>
        <location filename="../src/MainWindow.cpp" line="1060"/>
        <location filename="../src/MainWindow.cpp" line="1084"/>
        <location filename="../src/MainWindow.cpp" line="1109"/>
        <location filename="../src/MainWindow.cpp" line="1131"/>
        <source>All Groups</source>
        <translation>全てのグループ</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="578"/>
        <location filename="../ui/MainWindow.ui" line="58"/>
        <source>Installed packages</source>
        <translation>インストールされたパッケージ</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="586"/>
        <location filename="../ui/MainWindow.ui" line="63"/>
        <source>Not installed packages</source>
        <translation>インストールされていないパッケージ</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="593"/>
        <location filename="../ui/MainWindow.ui" line="68"/>
        <source>Upgradeable packages</source>
        <translation>アップグレード可能なパッケージ</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="601"/>
        <location filename="../ui/MainWindow.ui" line="73"/>
        <source>Packages in Queue</source>
        <translation>キュー中のパッケージ</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="689"/>
        <location filename="../src/MainWindow.cpp" line="991"/>
        <location filename="../src/MainWindow.cpp" line="999"/>
        <source>Mark for Re&amp;installation</source>
        <translation>再&amp;インストール要件としてマーク</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="697"/>
        <location filename="../src/MainWindow.cpp" line="970"/>
        <location filename="../ui/MainWindow.ui" line="316"/>
        <source>Mark for &amp;Installation</source>
        <translation>&amp;インストール要件としてマーク</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="704"/>
        <location filename="../src/MainWindow.cpp" line="1007"/>
        <location filename="../src/MainWindow.cpp" line="1218"/>
        <location filename="../src/MainWindow.cpp" line="1221"/>
        <location filename="../src/MainWindow.cpp" line="1256"/>
        <location filename="../src/MainWindow.cpp" line="1259"/>
        <location filename="../src/MainWindow.cpp" line="1797"/>
        <location filename="../src/MainWindow.cpp" line="2022"/>
        <source>Install</source>
        <translation>インストール</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="706"/>
        <location filename="../src/MainWindow.cpp" line="1009"/>
        <location filename="../src/MainWindow.cpp" line="1309"/>
        <location filename="../src/MainWindow.cpp" line="1312"/>
        <location filename="../src/MainWindow.cpp" line="1795"/>
        <location filename="../src/MainWindow.cpp" line="2032"/>
        <source>Uninstall</source>
        <translation>アンインストール</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="708"/>
        <location filename="../src/MainWindow.cpp" line="1336"/>
        <location filename="../src/MainWindow.cpp" line="1796"/>
        <location filename="../src/MainWindow.cpp" line="2033"/>
        <source>Complete Uninstall</source>
        <translation>インストール完了</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="761"/>
        <source>Status: </source>
        <translation>状態:</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="763"/>
        <source>Installed</source>
        <translation>インストールされている</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="765"/>
        <source>Not installed</source>
        <translation>インストールされていない</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="767"/>
        <source>Local Version: </source>
        <translation>ローカルバージョン:</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="771"/>
        <source>Version in the Repository: </source>
        <translation>リポジトリにあるバージョン:</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="776"/>
        <source>Action: </source>
        <translation>アクション:</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="870"/>
        <location filename="../src/MainWindow.cpp" line="1888"/>
        <source>Error</source>
        <translation>エラー</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="870"/>
        <location filename="../src/MainWindow.cpp" line="875"/>
        <source>One or more Databases could not be updated.
Last error reported was:
%1</source>
        <translation>少なくとも一つ以上のデータベースがアップデートできませんでした。
最後のエラー通知:
%1</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="875"/>
        <location filename="../src/MainWindow.cpp" line="886"/>
        <source>Database Update</source>
        <translation>データベースのアップデート</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="879"/>
        <source>One or more databases failed to update!</source>
        <translation>少なくとも一つ以上のデータベースのアップデートに失敗しました!</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="887"/>
        <location filename="../src/MainWindow.cpp" line="889"/>
        <source>Databases Updated Successfully</source>
        <translation>データベースのアップデートに成功</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="900"/>
        <location filename="../src/MainWindow.cpp" line="1446"/>
        <source>Pacman Update</source>
        <translation>Pacmanのアップデート</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="901"/>
        <location filename="../src/MainWindow.cpp" line="1446"/>
        <source>Pacman can be upgraded. It is advised to process it alone
to avoid version conflicts.
Do you want to Upgrade Pacman now?</source>
        <translation>Pacmanはアップグレード可能です。この通知は、バージョン衝突の解消の為のみに知らされました。
Pacmanを今すぐアップグレードしますか?</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="923"/>
        <location filename="../src/MainWindow.cpp" line="1465"/>
        <source>Shaman Update</source>
        <translation>Shamanアップデート</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="924"/>
        <location filename="../src/MainWindow.cpp" line="1465"/>
        <source>Shaman can be upgraded. It is advised to process it alone
to avoid version conflicts.
Do you want to Upgrade Shaman now?</source>
        <translation>Shamanはアップデート可能です。この通知はバージョン衝突回避のためだけに通知されました。
今すぐShamanをアップデートしますか?</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="973"/>
        <location filename="../ui/MainWindow.ui" line="336"/>
        <source>Mark for &amp;Removal</source>
        <translation>&amp;削除要件としてマーク</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="976"/>
        <source>Mark for Upgrade</source>
        <translation>アップグレード要件としてマーク</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="979"/>
        <location filename="../ui/MainWindow.ui" line="376"/>
        <source>&amp;Cancel Action</source>
        <translation>アクションを&amp;キャンセル</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="985"/>
        <location filename="../ui/MainWindow.ui" line="280"/>
        <source>Package Information</source>
        <translation>パッケージ情報</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1026"/>
        <source>Mark all for installation</source>
        <translation>全てインストール要件としてマーク</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1029"/>
        <source>Mark all for reinstallation</source>
        <translation>全て再インストール要件としてマーク</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1032"/>
        <source>Mark all for removal</source>
        <translation>全て削除要件としてマーク</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1035"/>
        <location filename="../ui/MainWindow.ui" line="644"/>
        <source>Cancel all actions</source>
        <translation>全てのアクションをキャンセル</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1159"/>
        <location filename="../ui/MainWindow.ui" line="13"/>
        <source>Shaman</source>
        <translation>Shaman</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1160"/>
        <source>A package providing %1 is already installed.
Do you want to install %1 anyway?</source>
        <translation>%1を提供しているパッケージは既にインストールされています。
それでも%1をインストールしますか?</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1424"/>
        <location filename="../src/MainWindow.cpp" line="1426"/>
        <source>System Upgrade</source>
        <translation>システムアップグレード</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1424"/>
        <location filename="../src/MainWindow.cpp" line="1426"/>
        <location filename="../src/MainWindow.cpp" line="1430"/>
        <source>Your system is up to date!</source>
        <translation>システムは最新です!</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1505"/>
        <location filename="../src/MainWindow.cpp" line="1775"/>
        <source>News Alert</source>
        <translation>ニュースアラート</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1506"/>
        <location filename="../src/MainWindow.cpp" line="1776"/>
        <source>There is an unread news about %1.
Do you want to read it?</source>
        <translation>%1に関する未読ニュースがあります。
読みますか?</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1561"/>
        <location filename="../src/MainWindow.cpp" line="1592"/>
        <location filename="../src/MainWindow.cpp" line="1798"/>
        <location filename="../src/MainWindow.cpp" line="2027"/>
        <source>Upgrade</source>
        <translation>アップグレード</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1626"/>
        <source>Queue Processing</source>
        <translation>キューの処理中</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1627"/>
        <source>Your Queue is being processed.
Please wait.</source>
        <translation>キューの処理中です。
しばらくお待ち下さい。</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1671"/>
        <location filename="../src/MainWindow.cpp" line="1675"/>
        <location filename="../src/MainWindow.cpp" line="1725"/>
        <location filename="../src/MainWindow.cpp" line="1727"/>
        <source>Queue Processed</source>
        <translation>キューの処理</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1672"/>
        <location filename="../src/MainWindow.cpp" line="1676"/>
        <source>One or more errors occurred, your Queue
was not successfully processed</source>
        <translation>少なくとも一つ以上のエラーが発生し、キューが正常に処理されませんでした</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1679"/>
        <source>Error Processing Queue!!</source>
        <translation>キューの処理中にエラー!</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1687"/>
        <location filename="../src/MainWindow.cpp" line="1696"/>
        <location filename="../src/MainWindow.cpp" line="1706"/>
        <location filename="../src/MainWindow.cpp" line="1715"/>
        <source>Restart required</source>
        <translation>再起動の要求</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1688"/>
        <location filename="../src/MainWindow.cpp" line="1697"/>
        <location filename="../src/MainWindow.cpp" line="1707"/>
        <source>Pacman or Shaman was updated. Shaman will now quit,
please restart it to use the new version</source>
        <translation>PacmanとShamanはアップデートされました。Shamanを一度終了しますが、新しいバージョンを使用する際は手動で再度、起動して下さい</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1715"/>
        <source>Your Kernel has been updated.
Please restart your PC soon to load the new Kernel.</source>
        <translation>カーネルのアップデートが完了しました。
新しいカーネルをロードするため、今すぐコンピュータを再起動して下さい。</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1725"/>
        <source>Your Queue was successfully processed!</source>
        <translation>キューは正常に処理されました!</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1728"/>
        <location filename="../src/MainWindow.cpp" line="1730"/>
        <source>Your Queue was successfully processed!!</source>
        <translation>キューは正常に処理されました!!</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1874"/>
        <source>Install a Package</source>
        <translation>パッケージのインストール</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1874"/>
        <source>Arch Linux Packages (*.pkg.tar.gz)</source>
        <translation>Arch Linux パッケージ(*.pkg.tar.gz)</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1888"/>
        <source>%1 does not seem
a valid package</source>
        <translation>%1は有効なパッケージではないようです</translation>
    </message>
    <message>
        <location filename="../src/MainWindow.cpp" line="1915"/>
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
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;A libalpm frontend in Qt&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;License: GPLv2+&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;Libalpm Version: v.%1&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;(C) 2008 Dario Freddi &amp;lt;drf@kdemod.ath.cx&amp;gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;(C) 2008 Lukas Appelhans &amp;lt;boom1992@kdemod.ath.cx&amp;gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="53"/>
        <source>All packages</source>
        <translation>全てのパッケージ</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="144"/>
        <source>Status</source>
        <translation>状態</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="154"/>
        <source>Action</source>
        <translation>アクション</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="159"/>
        <source>Version</source>
        <translation>バージョン</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="164"/>
        <source>Size</source>
        <translation>サイズ</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="169"/>
        <source>Repository</source>
        <translation>リポジトリ</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="174"/>
        <source>Groups</source>
        <translation>グループ</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="184"/>
        <source>Action-Text</source>
        <translation>アクションテキスト</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="231"/>
        <source>Re&amp;positories</source>
        <translation>リ&amp;ポジトリ</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="254"/>
        <source>Package &amp;Groups</source>
        <translation>パッケージ&amp;グループ</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="313"/>
        <source>Install selected package</source>
        <translation>選択されたパッケージをインストール</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="333"/>
        <source>Remove selected package</source>
        <translation>選択されたパッケージを削除</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="353"/>
        <source>Complete Remove selected package (pacman -Rcs)</source>
        <translation>選択されたパッケージを完全に削除(pacman -Rs)</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="356"/>
        <source>Mark for complete re&amp;moval</source>
        <translation>完全に削&amp;除する項目としてマーク</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="373"/>
        <source>Cancel action for selected package</source>
        <translation>選択されたパッケージに対するアクションを取り消し</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="415"/>
        <source>Package I&amp;nformation</source>
        <translation>パッケージに関する情&amp;報</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="451"/>
        <source>File&amp;s</source>
        <translation>ファイ&amp;ル</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="462"/>
        <source>1</source>
        <translation>一</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="471"/>
        <source>&amp;Dependencies</source>
        <translation>&amp;依存関係</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="504"/>
        <source>&amp;File</source>
        <translation>&amp;ファイル</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="510"/>
        <source>&amp;Help</source>
        <translation>&amp;ヘルプ</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="516"/>
        <source>&amp;Actions</source>
        <translation>&amp;アクション</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="520"/>
        <source>Build and Install from Source</source>
        <translation>提供元からビルドし、インストール</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="534"/>
        <source>&amp;Tools</source>
        <translation>&amp;ツール</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="551"/>
        <source>Quick Actions</source>
        <translation>クイックアクション</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="578"/>
        <source>Settings...</source>
        <translation>設定...</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="587"/>
        <source>About...</source>
        <translation>このソフトウェアについて...</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="596"/>
        <source>Upgrade System</source>
        <translation>システムをアップグレード</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="605"/>
        <source>Install Package From File</source>
        <translation>パッケージをファイルからインストール</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="617"/>
        <source>Update ABS Tree</source>
        <translation>ABSディレクトリ構造をアップデートする</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="626"/>
        <source>Build and Install Queue</source>
        <translation>キューをビルドし、インストール</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="635"/>
        <source>Quit</source>
        <comment>Quit the application</comment>
        <translation>終了</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="653"/>
        <source>Read News</source>
        <translation>ニュースを読む</translation>
    </message>
    <message>
        <location filename="../ui/MainWindow.ui" line="662"/>
        <source>View Log</source>
        <translation>ログを見る</translation>
    </message>
</context>
<context>
    <name>MaintenanceBar</name>
    <message>
        <location filename="../src/MaintenanceBar.cpp" line="40"/>
        <source>Maintenance Actions</source>
        <translation>メンテナンスアクション</translation>
    </message>
    <message>
        <location filename="../src/MaintenanceBar.cpp" line="44"/>
        <source>Please choose an action to start maintenance...</source>
        <translation>メンテナンスを開始するためのアクションを選択してください...</translation>
    </message>
    <message>
        <location filename="../src/MaintenanceBar.cpp" line="46"/>
        <source>Clean Unused Databases</source>
        <translation>使われていないデータベースを消去</translation>
    </message>
    <message>
        <location filename="../src/MaintenanceBar.cpp" line="47"/>
        <source>Clean Cache</source>
        <translation>キャッシュを消去</translation>
    </message>
    <message>
        <location filename="../src/MaintenanceBar.cpp" line="48"/>
        <source>Empty Cache</source>
        <translation>キャッシュを空に</translation>
    </message>
    <message>
        <location filename="../src/MaintenanceBar.cpp" line="49"/>
        <source>Optimize Pacman Database</source>
        <translation>Pacmanデータベースを最適化</translation>
    </message>
    <message>
        <location filename="../src/MaintenanceBar.cpp" line="50"/>
        <source>Clean All Building Environments</source>
        <translation>全てのビルド関係の消去</translation>
    </message>
    <message>
        <location filename="../src/MaintenanceBar.cpp" line="81"/>
        <location filename="../src/MaintenanceBar.cpp" line="82"/>
        <source>Cleaning up unused Databases...</source>
        <translation>使われていないデータベースを消去しています...</translation>
    </message>
    <message>
        <location filename="../src/MaintenanceBar.cpp" line="95"/>
        <location filename="../src/MaintenanceBar.cpp" line="96"/>
        <source>Cleaning up Cache...</source>
        <translation>キャッシュを消去しています...</translation>
    </message>
    <message>
        <location filename="../src/MaintenanceBar.cpp" line="109"/>
        <location filename="../src/MaintenanceBar.cpp" line="110"/>
        <source>Deleting Cache...</source>
        <translation>キャッシュを削除しています...</translation>
    </message>
    <message>
        <location filename="../src/MaintenanceBar.cpp" line="144"/>
        <location filename="../src/MaintenanceBar.cpp" line="145"/>
        <source>Cleaning up building Environments...</source>
        <translation>ビルド環境をクリーニング中...</translation>
    </message>
    <message>
        <location filename="../src/MaintenanceBar.cpp" line="171"/>
        <source>Abort</source>
        <translation>中止</translation>
    </message>
    <message>
        <location filename="../src/MaintenanceBar.cpp" line="184"/>
        <source>System Maintenance</source>
        <translation>システムメンテナンス</translation>
    </message>
    <message>
        <location filename="../src/MaintenanceBar.cpp" line="192"/>
        <location filename="../src/MaintenanceBar.cpp" line="193"/>
        <location filename="../src/MaintenanceBar.cpp" line="194"/>
        <source>Unused Databases Cleaned up successfully!</source>
        <translation>使われていないデータベースのクリーニングアップに成功!</translation>
    </message>
    <message>
        <location filename="../src/MaintenanceBar.cpp" line="198"/>
        <location filename="../src/MaintenanceBar.cpp" line="199"/>
        <location filename="../src/MaintenanceBar.cpp" line="200"/>
        <source>Cache Cleaned Up Successfully!</source>
        <translation>キャッシュの消去に成功!</translation>
    </message>
    <message>
        <location filename="../src/MaintenanceBar.cpp" line="204"/>
        <location filename="../src/MaintenanceBar.cpp" line="205"/>
        <location filename="../src/MaintenanceBar.cpp" line="206"/>
        <source>Cache Successfully Deleted!</source>
        <translation>キャッシュは正常に削除されました!</translation>
    </message>
    <message>
        <location filename="../src/MaintenanceBar.cpp" line="210"/>
        <location filename="../src/MaintenanceBar.cpp" line="211"/>
        <location filename="../src/MaintenanceBar.cpp" line="212"/>
        <source>Build Environments Successfully Cleaned!</source>
        <translation>ビルド環境は正常に消去されました!</translation>
    </message>
    <message>
        <location filename="../src/MaintenanceBar.cpp" line="218"/>
        <location filename="../src/MaintenanceBar.cpp" line="257"/>
        <location filename="../src/MaintenanceBar.cpp" line="310"/>
        <source>Close</source>
        <translation>閉じる</translation>
    </message>
    <message>
        <location filename="../src/MaintenanceBar.cpp" line="235"/>
        <location filename="../src/MaintenanceBar.cpp" line="236"/>
        <source>Cleaning up Unused Databases Failed!</source>
        <translation>使われていないデータベースの消去に失敗!</translation>
    </message>
    <message>
        <location filename="../src/MaintenanceBar.cpp" line="240"/>
        <location filename="../src/MaintenanceBar.cpp" line="241"/>
        <source>Cleaning up Cache Failed!</source>
        <translation>キャッシュの消去に失敗!</translation>
    </message>
    <message>
        <location filename="../src/MaintenanceBar.cpp" line="245"/>
        <location filename="../src/MaintenanceBar.cpp" line="246"/>
        <source>Deleting Cache Failed!</source>
        <translation>キャッシュの削除に失敗!</translation>
    </message>
    <message>
        <location filename="../src/MaintenanceBar.cpp" line="250"/>
        <location filename="../src/MaintenanceBar.cpp" line="251"/>
        <source>Could not clean Build Environments!!</source>
        <translation>ビルド環境をクリーンアップできませんでした!</translation>
    </message>
    <message>
        <location filename="../src/MaintenanceBar.cpp" line="275"/>
        <location filename="../src/MaintenanceBar.cpp" line="276"/>
        <location filename="../src/MaintenanceBar.cpp" line="277"/>
        <source>Pacman Database Optimized Successfully!</source>
        <translation>Pacmanデータベースの最適化に成功!</translation>
    </message>
    <message>
        <location filename="../src/MaintenanceBar.cpp" line="279"/>
        <location filename="../src/MaintenanceBar.cpp" line="280"/>
        <location filename="../src/MaintenanceBar.cpp" line="281"/>
        <source>Could not Optimize Pacman Database!</source>
        <translation>Pacmanデータベースの最適化に失敗しました!</translation>
    </message>
</context>
<context>
    <name>NewsViewer</name>
    <message>
        <location filename="../src/NewsViewer.cpp" line="47"/>
        <source>Please wait, fetching items...</source>
        <translation>項目を読み込み中です。しばらくお待ち下さい...</translation>
    </message>
    <message>
        <location filename="../src/NewsViewer.cpp" line="117"/>
        <source>Mark as Read</source>
        <translation>既読としてマーク</translation>
    </message>
    <message>
        <location filename="../src/NewsViewer.cpp" line="119"/>
        <source>Mark as Unread</source>
        <translation>未読としてマーク</translation>
    </message>
    <message>
        <location filename="../src/NewsViewer.cpp" line="175"/>
        <source>Error</source>
        <translation>エラー</translation>
    </message>
    <message>
        <location filename="../src/NewsViewer.cpp" line="175"/>
        <source>Could not fetch the RSS feed! Error reported was:</source>
        <translation>RSSフィードを読み込めませんでした。エラーレポートは:</translation>
    </message>
</context>
<context>
    <name>PackageProperties</name>
    <message>
        <location filename="../src/PackageProperties.cpp" line="49"/>
        <source>%1 GiB</source>
        <comment>Size is in Gib</comment>
        <translation>%1 Gib</translation>
    </message>
    <message>
        <location filename="../src/PackageProperties.cpp" line="51"/>
        <source>%1 MiB</source>
        <comment>Size is in MiB</comment>
        <translation>%1 MiB</translation>
    </message>
    <message>
        <location filename="../src/PackageProperties.cpp" line="53"/>
        <source>%1 KiB</source>
        <comment>Size is in KiB</comment>
        <translation>%1 KiB</translation>
    </message>
    <message>
        <location filename="../src/PackageProperties.cpp" line="55"/>
        <source>%1 Bytes</source>
        <comment>Size is in Bytes</comment>
        <translation>%1 Bytes</translation>
    </message>
    <message>
        <location filename="../src/PackageProperties.cpp" line="75"/>
        <source>Shaman - %1 properties</source>
        <translation>Shaman - %1 プロパティ</translation>
    </message>
    <message>
        <location filename="../src/PackageProperties.cpp" line="96"/>
        <source>N/A</source>
        <comment>Stands for: Not Available</comment>
        <translation>利用不可</translation>
    </message>
    <message>
        <location filename="../src/PackageProperties.cpp" line="203"/>
        <source>Changelog not available for this package</source>
        <translation>このパッケージに於ける変更ログはありません</translation>
    </message>
</context>
<context>
    <name>QObject</name>
    <message>
        <location filename="../src/MainWindow.cpp" line="1950"/>
        <source>Whoa, that&apos;s co&amp;ol!</source>
        <translation>ワオ、&amp;素晴らしい!</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="410"/>
        <location filename="../src/QueueDialog.cpp" line="447"/>
        <source>Ok</source>
        <translation>OK</translation>
    </message>
    <message>
        <location filename="../src/Shaman.cpp" line="69"/>
        <location filename="../src/Shaman.cpp" line="131"/>
        <location filename="../src/Shaman.cpp" line="140"/>
        <location filename="../src/Shaman.cpp" line="150"/>
        <location filename="../src/main.cpp" line="266"/>
        <source>Shaman</source>
        <translation>Shaman</translation>
    </message>
    <message>
        <location filename="../src/Shaman.cpp" line="69"/>
        <source>There was a problem while testing libalpm.
Maybe another application has a lock on it.</source>
        <translation>libalpmをテストするには問題がある
多分、他のアプリケーションがそれをロックしてる。</translation>
    </message>
    <message>
        <location filename="../src/Shaman.cpp" line="79"/>
        <source>Shaman</source>
        <comment>Hey! If you are reading this, first of all thanks for helping us in making Shaman better. There are not many comments unless where needed, since all the strings are pretty self-explanatory. You will see a lot of HTML in some cases: do not let that scare you, but please edit text only. Editing HTML tags too may break our layout, so be careful. A good practice could be copying the whole string, and then translating just what&apos;s outside the tags, usually just a few words. If you have any doubts, or if you just want to drop us a line, there goes our email addresses:
Dario: drf54321@gmail.com
Lukas: l.appelhans@gmx.de
Thanks again, and enjoy your translation!</comment>
        <translatorcomment>OK,I&apos;ll enjoy my translation!</translatorcomment>
        <translation>Shaman</translation>
    </message>
    <message>
        <location filename="../src/Shaman.cpp" line="88"/>
        <source>Your settings file seems unwritable.
Please check permissions on it.</source>
        <translation>書き込み不可能な設定のようです。
パーミッションをチェックして下さい。</translation>
    </message>
    <message>
        <location filename="../src/Shaman.cpp" line="126"/>
        <source>Please Wait...</source>
        <translation>しばらくお待ち下さい...</translation>
    </message>
    <message>
        <location filename="../src/Shaman.cpp" line="132"/>
        <source>Shaman can not be started as root.
Please restart it as unprivileged user.</source>
        <translation>Shamanをルート権限で起動することはできません。
ルート権を持っていないユーザで起動して下さい。</translation>
    </message>
    <message>
        <location filename="../src/Shaman.cpp" line="141"/>
        <source>You have started Shaman as root.
It is advised to start it as unprivileged user.
Shaman will ask you for root password when needed.</source>
        <translation>ルートとしてShamanを起動しています。
Shamanは必要時にルートパスワードを要求するため、非root権ユーザーで起動することをお勧めします。</translation>
    </message>
    <message>
        <location filename="../src/Shaman.cpp" line="150"/>
        <source>Pacman is not updated.
Shaman needs libalpm &gt;= 2.1.0 to run.
Yours is %1. Please update Pacman.</source>
        <translation>Pacmanはアップデートされません。
Shamanの起動にはlibalpmのバージョン2.1.0以降が必要です。
貴方のバージョンは%1です。Pacmanをアップデートして下さい。</translation>
    </message>
    <message>
        <location filename="../src/Shaman.cpp" line="200"/>
        <source>Loading Databases...</source>
        <translation>データベースのロード中...</translation>
    </message>
    <message>
        <location filename="../src/Shaman.cpp" line="206"/>
        <source>Loading Packages...</source>
        <translation>パッケージのロード中...</translation>
    </message>
    <message>
        <location filename="../src/Shaman.cpp" line="212"/>
        <source>Starting up Shaman...</source>
        <translation>Shamanを開始しています...</translation>
    </message>
    <message>
        <location filename="../src/ShamanDialog.cpp" line="80"/>
        <location filename="../src/ShamanDialog.cpp" line="218"/>
        <location filename="../src/configDialog.cpp" line="59"/>
        <source>O&amp;k</source>
        <translation>O&amp;K</translation>
    </message>
    <message>
        <location filename="../src/ShamanDialog.cpp" line="136"/>
        <source>&amp;Yes</source>
        <translation>&amp;はい</translation>
    </message>
    <message>
        <location filename="../src/ShamanDialog.cpp" line="138"/>
        <source>&amp;No</source>
        <translation>&amp;いいえ</translation>
    </message>
    <message>
        <location filename="../src/ShamanDialog.cpp" line="214"/>
        <source>Do not &amp;show this Again</source>
        <translation>二度とメッセージを&amp;表示しない</translation>
    </message>
    <message>
        <location filename="../src/configDialog.cpp" line="60"/>
        <source>C&amp;ancel</source>
        <translation>キ&amp;ャンセル</translation>
    </message>
    <message>
        <location filename="../src/main.cpp" line="267"/>
        <source>It looks like another copy of Shaman is running.
You can only run one copy of Shaman at a time.</source>
        <translation>Shamanが多重作動中のようです。
Shamanは1個しか起動できません。</translation>
    </message>
</context>
<context>
    <name>QueueDialog</name>
    <message>
        <location filename="../src/QueueDialog.cpp" line="73"/>
        <source>&lt;br&gt;&lt;b&gt; * Validating Transaction&lt;/b&gt;&lt;br&gt;</source>
        <translation>&lt;br&gt;&lt;b&gt; * トランザクションの検証中&lt;/b&gt;&lt;br&gt;</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="126"/>
        <location filename="../src/QueueDialog.cpp" line="127"/>
        <source>Validating Dependencies...</source>
        <translation>依存関係の検証中...</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="130"/>
        <location filename="../src/QueueDialog.cpp" line="131"/>
        <source>Checking for Conflicts...</source>
        <translation>重複をチェック中...</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="134"/>
        <location filename="../src/QueueDialog.cpp" line="135"/>
        <source>Resolving Dependencies...</source>
        <translation>依存関係の解消中...</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="138"/>
        <location filename="../src/QueueDialog.cpp" line="139"/>
        <source>Looking for Inter-Conflicts...</source>
        <translation>競合を探しています...</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="144"/>
        <source>&lt;br&gt;&lt;b&gt; * Package Installation Started&lt;/b&gt;&lt;br&gt;</source>
        <translation>&lt;br&gt;&lt;b&gt; * パッケージのインストールを開始</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="147"/>
        <location filename="../src/QueueDialog.cpp" line="148"/>
        <source>Installing %1...</source>
        <translation>インストール中:%1...</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="152"/>
        <source>%1 (%2) installed successfully!</source>
        <translation>%1(%2)のインストールに成功!</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="163"/>
        <source>&lt;br&gt;&lt;b&gt; * Package Removal Started&lt;/b&gt;&lt;br&gt;</source>
        <translation>&lt;br&gt;&lt;b&gt; * パッケージの削除を開始&lt;/b&gt;&lt;br&gt;</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="166"/>
        <location filename="../src/QueueDialog.cpp" line="167"/>
        <source>Removing %1...</source>
        <translation>削除中:%1...</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="170"/>
        <source>%1 (%2) removed successfully!</source>
        <translation>%1 (%2)の削除に成功!</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="181"/>
        <source>&lt;br&gt;&lt;b&gt; * Package Upgrading Started&lt;/b&gt;&lt;br&gt;</source>
        <translation>&lt;br&gt;&lt;b&gt; * パッケージのアップグレードを開始&lt;/b&gt;&lt;br&gt;</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="184"/>
        <location filename="../src/QueueDialog.cpp" line="185"/>
        <source>Upgrading %1...</source>
        <translation>アップグレード中 %1...</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="188"/>
        <source>Upgraded %1 successfully (%2 -&gt; %3)</source>
        <translation>%1のアップデートに成功(%2-&gt;%3)</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="201"/>
        <source>&lt;br&gt;&lt;b&gt; * Queue Processing Started&lt;/b&gt;&lt;br&gt;</source>
        <translation>&lt;br&gt;&lt;b&gt; * キューの処理を開始&lt;/b&gt;&lt;br&gt;</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="204"/>
        <location filename="../src/QueueDialog.cpp" line="205"/>
        <source>Checking package integrity...</source>
        <translation>パッケージの整合性をチェック中...</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="208"/>
        <location filename="../src/QueueDialog.cpp" line="209"/>
        <source>Checking delta integrity...</source>
        <translation>差分の整合性をチェック中...</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="212"/>
        <source>Applying deltas...</source>
        <translation>デルタの適用中...</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="215"/>
        <source>Generating %1 with %2... </source>
        <translation>%2による%1を作成中...</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="219"/>
        <source>Success!</source>
        <translation>成功!</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="222"/>
        <source>Failed!</source>
        <translation>失敗!</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="231"/>
        <source>&lt;br&gt;&lt;b&gt; * Package Downloading Started&lt;/b&gt;&lt;br&gt;</source>
        <translation>&lt;br&gt;&lt;b&gt; * パッケージのダウンロードを開始&lt;/b&gt;&lt;br&gt;</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="234"/>
        <location filename="../src/QueueDialog.cpp" line="235"/>
        <source>Starting downloading packages from %1...</source>
        <translation>%1からパッケージのダウンロードを開始...</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="269"/>
        <source>%p% (%1 KB/s, %4:%5:%6 remaining)</source>
        <comment>You just have to translate &apos;remaining&apos; here. Leave everything else as it is.</comment>
        <translation>%p% (%1 KB/s, 残り時間:%4:%5:%6)</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="278"/>
        <source>Downloading %1... (%2 MB of %3 MB)</source>
        <translation>ダウンロード中:%1... (%2 MB of %3 MB)</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="281"/>
        <source>Downloading %1... (%2 KB of %3 KB)</source>
        <translation>ダウンロード中:%1... (%2 KB of %3 KB)</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="341"/>
        <source>Queue processed, please wait...</source>
        <translation>キューを処理中です。しばらくお待ち下さい...</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="348"/>
        <location filename="../src/QueueDialog.cpp" line="349"/>
        <source>Queue processing failed!</source>
        <translation>キューの処理に失敗!</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="351"/>
        <location filename="../src/QueueDialog.cpp" line="352"/>
        <source>Queue processed successfully!</source>
        <translation>キューの処理に成功!</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="359"/>
        <source>Close</source>
        <translation>閉じる</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="369"/>
        <location filename="../src/QueueDialog.cpp" line="418"/>
        <location filename="../src/QueueDialog.cpp" line="455"/>
        <source>Queue Processing</source>
        <translation>キューを処理中</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="370"/>
        <source>Would you like to abort Queue Processing?
This may damage your system.</source>
        <translation>キューの処理を中止しますか?
中止するとシステムにダメージを与える可能性があります。</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="404"/>
        <source>There has been an error while preparing the transaction.
</source>
        <translation>トランザクションの準備中にエラーが発生しました。
</translation>
    </message>
    <message>
        <location filename="../src/QueueDialog.cpp" line="441"/>
        <source>There has been an error while committing the transaction.
</source>
        <translation>トランザクションのコミット中にエラーが発生しました。</translation>
    </message>
</context>
<context>
    <name>QueueReadyDialog</name>
    <message>
        <location filename="../ui/reviewQueueDialog.ui" line="13"/>
        <source>Review Queue</source>
        <translation>キューレビュー</translation>
    </message>
    <message>
        <location filename="../ui/reviewQueueDialog.ui" line="32"/>
        <source>Force Queue Processing</source>
        <translation>強制的にキューを処理する</translation>
    </message>
    <message>
        <location filename="../ui/reviewQueueDialog.ui" line="39"/>
        <source>Turn off PC when Queue is done</source>
        <translation>キューの処理が完了後、PCをシャットダウンする</translation>
    </message>
    <message>
        <location filename="../ui/reviewQueueDialog.ui" line="46"/>
        <source>Process in Tray</source>
        <translation>タスクトレイで作業する</translation>
    </message>
    <message>
        <location filename="../ui/reviewQueueDialog.ui" line="53"/>
        <source>Keep Queue Dialog Open after the Queue is finished</source>
        <translation>キューの処理が完了してもこのダイアログを閉じない</translation>
    </message>
    <message>
        <location filename="../ui/reviewQueueDialog.ui" line="62"/>
        <source>Show packages...</source>
        <translation>パッケージを見る...</translation>
    </message>
    <message>
        <location filename="../ui/reviewQueueDialog.ui" line="92"/>
        <source>Packages In Queue</source>
        <translation>キュー中のパッケージ</translation>
    </message>
    <message>
        <location filename="../ui/reviewQueueDialog.ui" line="102"/>
        <source>Cancel</source>
        <translation>キャンセル</translation>
    </message>
    <message>
        <location filename="../ui/reviewQueueDialog.ui" line="126"/>
        <source>Process</source>
        <translation>開始</translation>
    </message>
    <message>
        <location filename="../ui/reviewQueueDialog.ui" line="156"/>
        <source>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Review Queue&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;キューレビュー&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
</context>
<context>
    <name>ReviewQueueDialog</name>
    <message>
        <location filename="../src/ReviewQueueDialog.cpp" line="42"/>
        <location filename="../src/ReviewQueueDialog.cpp" line="56"/>
        <source>Install</source>
        <translation>インストール</translation>
    </message>
    <message>
        <location filename="../src/ReviewQueueDialog.cpp" line="43"/>
        <location filename="../src/ReviewQueueDialog.cpp" line="59"/>
        <source>To be Installed</source>
        <translation>インストールするもの</translation>
    </message>
    <message>
        <location filename="../src/ReviewQueueDialog.cpp" line="46"/>
        <location filename="../src/ReviewQueueDialog.cpp" line="64"/>
        <source>Upgrade</source>
        <translation>アップグレード</translation>
    </message>
    <message>
        <location filename="../src/ReviewQueueDialog.cpp" line="47"/>
        <location filename="../src/ReviewQueueDialog.cpp" line="67"/>
        <source>To be Upgraded</source>
        <translation>アップグレードする</translation>
    </message>
    <message>
        <location filename="../src/ReviewQueueDialog.cpp" line="50"/>
        <location filename="../src/ReviewQueueDialog.cpp" line="72"/>
        <source>Uninstall</source>
        <translation>アンインストール</translation>
    </message>
    <message>
        <location filename="../src/ReviewQueueDialog.cpp" line="51"/>
        <location filename="../src/ReviewQueueDialog.cpp" line="75"/>
        <location filename="../src/ReviewQueueDialog.cpp" line="83"/>
        <source>To be Removed</source>
        <translation>削除するもの</translation>
    </message>
    <message>
        <location filename="../src/ReviewQueueDialog.cpp" line="80"/>
        <source>Complete Uninstall</source>
        <translation>完全にアンインストール</translation>
    </message>
    <message>
        <location filename="../src/ReviewQueueDialog.cpp" line="101"/>
        <source>Your Queue is about to be processed. You are going to:&lt;br /&gt;</source>
        <translation>キューが処理されたようです、貴方は:&lt;br /&gt;</translation>
    </message>
    <message numerus="yes">
        <location filename="../src/ReviewQueueDialog.cpp" line="104"/>
        <source>Remove &lt;b&gt;%n package(s)&lt;/b&gt;&lt;br /&gt;</source>
        <translation>
            <numerusform>&lt;b&gt;%n個のパッケージ&lt;/b&gt;を削除&lt;br /&gt;</numerusform>
        </translation>
    </message>
    <message numerus="yes">
        <location filename="../src/ReviewQueueDialog.cpp" line="106"/>
        <source>Install/Upgrade &lt;b&gt;%n package(s)&lt;/b&gt;&lt;br /&gt;</source>
        <translation>
            <numerusform>&lt;b&gt;%n個のパッケージ&lt;/b&gt;をインストール/アップグレード&lt;br /&gt;</numerusform>
        </translation>
    </message>
    <message>
        <location filename="../src/ReviewQueueDialog.cpp" line="107"/>
        <source>Do you wish to continue?</source>
        <translation>続行しますか?</translation>
    </message>
</context>
<context>
    <name>ShamanStatusBar</name>
    <message>
        <location filename="../src/ShamanStatusBar.cpp" line="83"/>
        <source>%1 Available Packages, %2 Installed Packages, %3 Upgradeable Packages</source>
        <translation>%1個の利用可能なパッケージ、%2個のインストール済みパッケージ、%3個のアップグレード可能なパッケージ</translation>
    </message>
    <message>
        <location filename="../src/ShamanStatusBar.cpp" line="109"/>
        <source>%1 will be used</source>
        <translation>使用予定:%1</translation>
    </message>
    <message>
        <location filename="../src/ShamanStatusBar.cpp" line="114"/>
        <source>%1 will be freed</source>
        <translation>解放予定:%1</translation>
    </message>
    <message>
        <location filename="../src/ShamanStatusBar.cpp" line="119"/>
        <source>%1 to be Installed, %2 to be Removed</source>
        <translation>%1項目がインストールされ、%2項目が削除される</translation>
    </message>
</context>
<context>
    <name>ShamanTrayIcon</name>
    <message>
        <location filename="../src/ShamanTrayIcon.cpp" line="48"/>
        <source>Update Database</source>
        <translation>データベースをアップデート</translation>
    </message>
    <message>
        <location filename="../src/ShamanTrayIcon.cpp" line="52"/>
        <source>Upgrade System</source>
        <translation>システムをアップデート</translation>
    </message>
    <message>
        <location filename="../src/ShamanTrayIcon.cpp" line="56"/>
        <source>Process Queue</source>
        <translation>プロセスを処理</translation>
    </message>
    <message>
        <location filename="../src/ShamanTrayIcon.cpp" line="61"/>
        <source>Settings</source>
        <translation>設定</translation>
    </message>
    <message>
        <location filename="../src/ShamanTrayIcon.cpp" line="66"/>
        <source>Quit</source>
        <translation>終了</translation>
    </message>
    <message>
        <location filename="../src/ShamanTrayIcon.cpp" line="111"/>
        <source>Shaman - Idle</source>
        <translation>Shaman - アイドル状態</translation>
    </message>
    <message>
        <location filename="../src/ShamanTrayIcon.cpp" line="123"/>
        <source>Shaman - Processing</source>
        <translation>Shaman - 処理中</translation>
    </message>
    <message>
        <location filename="../src/ShamanTrayIcon.cpp" line="128"/>
        <source>Shaman - Idle (Upgrades Available)</source>
        <translation>Shaman - アイドル状態(更新が利用可能です)</translation>
    </message>
    <message>
        <location filename="../src/ShamanTrayIcon.cpp" line="132"/>
        <source>System Upgrade</source>
        <translation>システムアップグレード</translation>
    </message>
    <message numerus="yes">
        <location filename="../src/ShamanTrayIcon.cpp" line="132"/>
        <source>Upgradeable package(s): %n.
Click here to upgrade your System.</source>
        <translation>
            <numerusform>アップグレード可能なパッケージ数:%n。
システムをアップグレードするにはここをクリックして下さい。</numerusform>
        </translation>
    </message>
    <message>
        <location filename="../src/ShamanTrayIcon.cpp" line="242"/>
        <source>New News Available</source>
        <translation>新しいニュースが利用可能です</translation>
    </message>
    <message>
        <location filename="../src/ShamanTrayIcon.cpp" line="242"/>
        <source>There are new news available.
Click here to review them.</source>
        <translation>新しいニュースが利用可能です。
読むにはここをクリックして下さい。</translation>
    </message>
    <message>
        <location filename="../src/ShamanTrayIcon.cpp" line="258"/>
        <source>Failed Fetching News</source>
        <translation>ニュースの読み込みに失敗</translation>
    </message>
    <message>
        <location filename="../src/ShamanTrayIcon.cpp" line="258"/>
        <source>An error occourred while fetching news!
Click here to open the News Dialog for more details.</source>
        <translation>ニュースの読み込み中にエラーが発生しました!
詳細を見るにはここをクリックして下さい。</translation>
    </message>
</context>
<context>
    <name>SysUpgradeDialog</name>
    <message numerus="yes">
        <location filename="../src/SysUpgradeDialog.cpp" line="64"/>
        <source>&lt;b&gt;Upgradeable package(s): %n&lt;/b&gt; You can either&lt;br&gt; upgrade immediately or add it to the current Queue&lt;br&gt; and process it later.</source>
        <translation>
            <numerusform>&lt;b&gt;アップグレード可能なパッケージ数: %n&lt;/b&gt;&lt;br /&gt;あなたはシステムを今すぐアップグレードするか、キューに含め、後で処理することができます。</numerusform>
        </translation>
    </message>
    <message>
        <location filename="../src/SysUpgradeDialog.cpp" line="69"/>
        <source>To be Upgraded</source>
        <translation>アップグレードする</translation>
    </message>
</context>
<context>
    <name>aboutDialog</name>
    <message>
        <location filename="../ui/aboutDialog.ui" line="13"/>
        <source>About Shaman</source>
        <translation>Shamanについて</translation>
    </message>
    <message>
        <location filename="../ui/aboutDialog.ui" line="88"/>
        <source>About</source>
        <translation>About</translation>
    </message>
    <message>
        <location filename="../ui/aboutDialog.ui" line="106"/>
        <source>Authors</source>
        <translation>作者</translation>
    </message>
    <message>
        <location filename="../ui/aboutDialog.ui" line="116"/>
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
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;開発者&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Lukas Appelhans&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;開発者&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../ui/aboutDialog.ui" line="132"/>
        <source>Thanks To</source>
        <translation>スペシャルサンクス</translation>
    </message>
    <message>
        <location filename="../ui/aboutDialog.ui" line="148"/>
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
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;&quot;&gt;&lt;span style=&quot; font-size:10pt;&quot;&gt;Shamanは多くの人々の手助けを受け、また、手助けを行って下さった方々に感謝します。もし、この中にリストされていない協力者がいる場合は、私たちにお知らせ下さい。&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;小さな功績であっても私たちにとって重要であると考えている為、私たちはアルファベット順に並べかえています。&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;The KDEmod コミュニティ&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;手助け、テスト、サポート、全てはここから始まっています。もし、KDEmodが存在していないのなら、多分、&lt;/span&gt; &lt;span style=&quot; font-weight:400;&quot;&gt;今のShamanは無かったかもしれません。&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Giannis Antoniou&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;翻訳(ギリシャ語)&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Carlos Berroteran&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;翻訳(スペイン語)&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Sander De Voogdt&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;翻訳(オランダ語)&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Jacques Disner&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;翻訳(フランス語)&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Jan Dupal&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;翻訳(チェコ語)&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Stefano Giro&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;テストと提案&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Georg Grabler&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;プロクシパッチの作成とコード等に対するいくつかの手助け&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Michael Knights&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;アートワークの作成。彼のアイコンはArxinに派生していますが、スプラッシュスクリーンはここにあります;)&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Till Luge&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;大規模なテスト 有難う!&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Rodrigo Mazak&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;翻訳(ブラジル語)と「Shaman」の命名者&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;Jan Mette&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;翻訳(ドイツ語)とKDEmodの開発、アイコンの作成&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Atilla Ontas&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;翻訳(トルコ語)&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Martin Sandsmark&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;ホストとメンテナンス&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Johannes Schriewer&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;KDEmodの開発とコードの手助け&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Xiang Yixiang&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;翻訳(中国語)&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Anton Gritsay&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;翻訳(ロシア語)と言語関係のパッチ当て&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Bartek Iwaniec&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;翻訳(ポーランド語)&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Marko Doda&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;翻訳(マケドニア語)&lt;/span&gt;&lt;/p&gt;&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Hiroaki Yamamoto&lt;/span&gt;&lt;/p&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;&quot;&gt;&lt;span style=&quot; font-weight:400;&quot;&gt;翻訳(日本語)&lt;/span&gt;&lt;/p&gt;&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../ui/aboutDialog.ui" line="223"/>
        <source>Visit &amp;Website...</source>
        <translation>&amp;サイトを訪れる...</translation>
    </message>
</context>
<context>
    <name>authDialog</name>
    <message>
        <location filename="../ui/authDialog.ui" line="13"/>
        <source>Root Password Required</source>
        <translation>ルートパスワード要求</translation>
    </message>
    <message>
        <location filename="../ui/authDialog.ui" line="37"/>
        <source>Shaman needs root privileges to perform this action.
Please enter in the field below the root password to continue.</source>
        <translation>このアクションを実行するにはroot権限が必要です。
続けるにはrootパスワードを入力して下さい。</translation>
    </message>
    <message>
        <location filename="../ui/authDialog.ui" line="60"/>
        <source>Never ask for this anymore</source>
        <translation>今後、この質問をしない</translation>
    </message>
    <message>
        <location filename="../ui/authDialog.ui" line="80"/>
        <source>Ok</source>
        <translation>OK</translation>
    </message>
    <message>
        <location filename="../ui/authDialog.ui" line="87"/>
        <source>Return</source>
        <translation>Enter</translation>
    </message>
    <message>
        <location filename="../ui/authDialog.ui" line="94"/>
        <source>Cancel</source>
        <translation>キャンセル</translation>
    </message>
    <message>
        <location filename="../ui/authDialog.ui" line="101"/>
        <source>Backspace</source>
        <translation>Backspace</translation>
    </message>
</context>
<context>
    <name>buildingDialog</name>
    <message>
        <location filename="../ui/buildingDialog.ui" line="13"/>
        <source>Shaman - Building Packages</source>
        <translation>Shaman - パッケージをビルド中</translation>
    </message>
    <message>
        <location filename="../ui/buildingDialog.ui" line="403"/>
        <source>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Liberation Sans&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Building Packages...&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Liberation Sans&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;パッケージをビルド中...&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../ui/buildingDialog.ui" line="467"/>
        <source>Abort</source>
        <translation>中止</translation>
    </message>
    <message>
        <location filename="../ui/buildingDialog.ui" line="490"/>
        <source>Reduce To Tray</source>
        <translation>トレイに格納</translation>
    </message>
</context>
<context>
    <name>dbUpdateDialog</name>
    <message>
        <location filename="../ui/dbUpdateDialog.ui" line="13"/>
        <source>Database Update</source>
        <translation>データベースのアップデート</translation>
    </message>
    <message>
        <location filename="../ui/dbUpdateDialog.ui" line="401"/>
        <source>Update Database..</source>
        <translation>データベースをアップデート..</translation>
    </message>
</context>
<context>
    <name>editPBDialog</name>
    <message>
        <location filename="../ui/editPBDialog.ui" line="13"/>
        <source>Editing PKGBUILD</source>
        <translation>PKGBUILDの編集</translation>
    </message>
    <message>
        <location filename="../ui/editPBDialog.ui" line="26"/>
        <source>Editing PKGBUILD of:</source>
        <translation>編集元:</translation>
    </message>
    <message>
        <location filename="../ui/editPBDialog.ui" line="40"/>
        <source>Save</source>
        <translation>保存</translation>
    </message>
    <message>
        <location filename="../ui/editPBDialog.ui" line="63"/>
        <source>Undo</source>
        <translation>元に戻す</translation>
    </message>
    <message>
        <location filename="../ui/editPBDialog.ui" line="73"/>
        <source>Redo</source>
        <translation>やり直し</translation>
    </message>
    <message>
        <location filename="../ui/editPBDialog.ui" line="110"/>
        <source>Ok</source>
        <translation>OK</translation>
    </message>
    <message>
        <location filename="../ui/editPBDialog.ui" line="133"/>
        <source>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Edit PKGBUILD&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;PKGBUILDを編集&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
</context>
<context>
    <name>logViewer</name>
    <message>
        <location filename="../ui/logViewer.ui" line="13"/>
        <source>Shaman - Log Viewer</source>
        <translation>Shaman - ログビュワー</translation>
    </message>
    <message>
        <location filename="../ui/logViewer.ui" line="23"/>
        <source>Show Only Logs From</source>
        <translation>次の日付から後のみ表示</translation>
    </message>
    <message>
        <location filename="../ui/logViewer.ui" line="35"/>
        <location filename="../ui/logViewer.ui" line="66"/>
        <source>dd/MM/yyyy</source>
        <translation>yyyy/MM/dd</translation>
    </message>
    <message>
        <location filename="../ui/logViewer.ui" line="54"/>
        <source>Show Only Logs Until</source>
        <translation>次の日付まで表示</translation>
    </message>
    <message>
        <location filename="../ui/logViewer.ui" line="79"/>
        <source>Filter</source>
        <translation>フィルター</translation>
    </message>
    <message>
        <location filename="../ui/logViewer.ui" line="109"/>
        <source>&lt;!DOCTYPE HTML PUBLIC &quot;-//W3C//DTD HTML 4.0//EN&quot; &quot;http://www.w3.org/TR/REC-html40/strict.dtd&quot;&gt;
&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Liberation Sans&apos;; font-size:9pt;&quot;&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translatorcomment>&lt;!DOCTYPE HTML PUBLIC &quot;-//W3C//DTD HTML 4.0//EN&quot; &quot;http://www.w3.org/TR/REC-html40/strict.dtd&quot;&gt;
&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Liberation Sans&apos;; font-size:9pt;&quot;&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translatorcomment>
        <translation>&lt;!DOCTYPE HTML PUBLIC &quot;-//W3C//DTD HTML 4.0//EN&quot; &quot;http://www.w3.org/TR/REC-html40/strict.dtd&quot;&gt;
&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot;-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Liberation Sans&apos;; font-size:9pt;&quot;&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../ui/logViewer.ui" line="139"/>
        <source>Refresh View</source>
        <translation>ビューの更新</translation>
    </message>
    <message>
        <location filename="../ui/logViewer.ui" line="156"/>
        <source>Close</source>
        <comment>close the dialog</comment>
        <translation>閉じる</translation>
    </message>
</context>
<context>
    <name>newsDialog</name>
    <message>
        <location filename="../ui/newsDialog.ui" line="13"/>
        <source>Arch Linux News</source>
        <translation>Arch Linux ニュース</translation>
    </message>
    <message>
        <location filename="../ui/newsDialog.ui" line="43"/>
        <source>News-Title</source>
        <translation>ニュースタイトル</translation>
    </message>
    <message>
        <location filename="../ui/newsDialog.ui" line="52"/>
        <source>Link</source>
        <translation>リンク</translation>
    </message>
    <message>
        <location filename="../ui/newsDialog.ui" line="61"/>
        <source>status</source>
        <translation>状態</translation>
    </message>
    <message>
        <location filename="../ui/newsDialog.ui" line="81"/>
        <source>Mark as Read</source>
        <translation>既読に設定</translation>
    </message>
    <message>
        <location filename="../ui/newsDialog.ui" line="92"/>
        <source>Open in Browser</source>
        <translation>ブラウザで開く</translation>
    </message>
    <message>
        <location filename="../ui/newsDialog.ui" line="103"/>
        <source>Refresh</source>
        <translation>更新</translation>
    </message>
    <message>
        <location filename="../ui/newsDialog.ui" line="127"/>
        <source>Close</source>
        <comment>close the dialog</comment>
        <translation>閉じる</translation>
    </message>
</context>
<context>
    <name>pkgProperties</name>
    <message>
        <location filename="../ui/pkgProperties.ui" line="46"/>
        <source>&lt;!DOCTYPE HTML PUBLIC &quot;-//W3C//DTD HTML 4.0//EN&quot; &quot;http://www.w3.org/TR/REC-html40/strict.dtd&quot;&gt;
&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Bitstream Vera Sans&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Package Information&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;!DOCTYPE HTML PUBLIC &quot;-//W3C//DTD HTML 4.0//EN&quot; &quot;http://www.w3.org/TR/REC-html40/strict.dtd&quot;&gt;
&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Bitstream Vera Sans&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;パッケージインフォメーション&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../ui/pkgProperties.ui" line="100"/>
        <source>Package Information</source>
        <translation>情報</translation>
    </message>
    <message>
        <location filename="../ui/pkgProperties.ui" line="106"/>
        <source>Installed:</source>
        <translation>インストールされているか:</translation>
    </message>
    <message>
        <location filename="../ui/pkgProperties.ui" line="113"/>
        <source>Description:</source>
        <translation>説明:</translation>
    </message>
    <message>
        <location filename="../ui/pkgProperties.ui" line="120"/>
        <source>Upgradeable</source>
        <translation>アップグレード可能</translation>
    </message>
    <message>
        <location filename="../ui/pkgProperties.ui" line="146"/>
        <source>Build Date:</source>
        <translation>ビルドされた日:</translation>
    </message>
    <message>
        <location filename="../ui/pkgProperties.ui" line="166"/>
        <source>Provides:</source>
        <translation>提供:</translation>
    </message>
    <message>
        <location filename="../ui/pkgProperties.ui" line="173"/>
        <source>Install Date:</source>
        <translation>インストールした日:</translation>
    </message>
    <message>
        <location filename="../ui/pkgProperties.ui" line="183"/>
        <source>Packager:</source>
        <translation>担当者:</translation>
    </message>
    <message>
        <location filename="../ui/pkgProperties.ui" line="190"/>
        <source>Size:</source>
        <translation>サイズ:</translation>
    </message>
    <message>
        <location filename="../ui/pkgProperties.ui" line="197"/>
        <source>Has a Scriptlet</source>
        <translation>Scriptの一種かどうか</translation>
    </message>
    <message>
        <location filename="../ui/pkgProperties.ui" line="274"/>
        <source>Version:</source>
        <translation>バージョン:</translation>
    </message>
    <message>
        <location filename="../ui/pkgProperties.ui" line="290"/>
        <source>Changelog</source>
        <translation>変更点</translation>
    </message>
    <message>
        <location filename="../ui/pkgProperties.ui" line="318"/>
        <source>Files</source>
        <translation>ファイル</translation>
    </message>
    <message>
        <location filename="../ui/pkgProperties.ui" line="325"/>
        <source>1</source>
        <translation>一</translation>
    </message>
    <message>
        <location filename="../ui/pkgProperties.ui" line="342"/>
        <source>Dependencies</source>
        <translation>依存関係</translation>
    </message>
    <message>
        <location filename="../ui/pkgProperties.ui" line="348"/>
        <source>Depends on</source>
        <translation>このパッケージが依存しているもの</translation>
    </message>
    <message>
        <location filename="../ui/pkgProperties.ui" line="355"/>
        <source>Is Required by</source>
        <translation>このパッケージに依存しているもの</translation>
    </message>
    <message>
        <location filename="../ui/pkgProperties.ui" line="377"/>
        <source>Actions Performed</source>
        <translation>挙動ログ</translation>
    </message>
    <message>
        <location filename="../ui/pkgProperties.ui" line="415"/>
        <source>Ok</source>
        <translation>OK</translation>
    </message>
</context>
<context>
    <name>reviewBuildingDialog</name>
    <message>
        <location filename="../ui/reviewBuildingDialog.ui" line="13"/>
        <source>Review Building Queue</source>
        <translation>ビルド中のキューのレビュー</translation>
    </message>
    <message>
        <location filename="../ui/reviewBuildingDialog.ui" line="40"/>
        <source>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Liberation Sans&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Build Queue From Source&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Liberation Sans&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:&apos;Sans Serif&apos;;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;ソースからキューをビルド&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../ui/reviewBuildingDialog.ui" line="85"/>
        <source>Process All Dependencies from Binary First (advised)</source>
        <translation>最初に全ての依存関係をバイナリから処理する (注意して下さい)</translation>
    </message>
    <message>
        <location filename="../ui/reviewBuildingDialog.ui" line="95"/>
        <source>This is useful if you want to review compiler&apos;s output</source>
        <translation>コンパイラからの出力を表示する</translation>
    </message>
    <message>
        <location filename="../ui/reviewBuildingDialog.ui" line="98"/>
        <source>Do not install immediately when building is finished</source>
        <translation>ビルド完了後、すぐにインストールしない</translation>
    </message>
    <message>
        <location filename="../ui/reviewBuildingDialog.ui" line="108"/>
        <source>Turn off PC when Queue is done</source>
        <translation>キューの処理が完了したら、PCの電源を切る</translation>
    </message>
    <message>
        <location filename="../ui/reviewBuildingDialog.ui" line="117"/>
        <source>Show packages...</source>
        <translation>パッケージを見る...</translation>
    </message>
    <message>
        <location filename="../ui/reviewBuildingDialog.ui" line="147"/>
        <source>Packages In Queue</source>
        <translation>キュー中のパッケージ</translation>
    </message>
    <message>
        <location filename="../ui/reviewBuildingDialog.ui" line="157"/>
        <source>Abort</source>
        <translation>中止</translation>
    </message>
    <message>
        <location filename="../ui/reviewBuildingDialog.ui" line="168"/>
        <source>Process From Binary</source>
        <translation>バイナリから処理</translation>
    </message>
    <message>
        <location filename="../ui/reviewBuildingDialog.ui" line="192"/>
        <source>Review PKGBUILDs</source>
        <translation>PKGBUILDsを表示</translation>
    </message>
    <message>
        <location filename="../ui/reviewBuildingDialog.ui" line="203"/>
        <source>Process From Source</source>
        <translation>ソースから処理</translation>
    </message>
</context>
<context>
    <name>transactionDialog</name>
    <message>
        <location filename="../ui/transactionDialog.ui" line="13"/>
        <source>Processing Queue...</source>
        <translation>キューの処理中...</translation>
    </message>
    <message>
        <location filename="../ui/transactionDialog.ui" line="25"/>
        <source>Check transaction validity</source>
        <translation>トランザクションの有効性の確認</translation>
    </message>
    <message>
        <location filename="../ui/transactionDialog.ui" line="32"/>
        <source>Download Packages</source>
        <translation>パッケージのダウンロード</translation>
    </message>
    <message>
        <location filename="../ui/transactionDialog.ui" line="39"/>
        <source>Process queue</source>
        <translation>キューの処理</translation>
    </message>
    <message>
        <location filename="../ui/transactionDialog.ui" line="46"/>
        <source>Cleanup</source>
        <translation>クリーンアップ</translation>
    </message>
    <message>
        <location filename="../ui/transactionDialog.ui" line="138"/>
        <source>More Details...</source>
        <translation>詳細...</translation>
    </message>
    <message>
        <location filename="../ui/transactionDialog.ui" line="168"/>
        <source>Abort</source>
        <translation>中止</translation>
    </message>
    <message>
        <location filename="../ui/transactionDialog.ui" line="187"/>
        <source>Please Wait...</source>
        <translation>しばらくお待ち下さい...</translation>
    </message>
    <message>
        <location filename="../ui/transactionDialog.ui" line="218"/>
        <source>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;Process Queue&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;キューの処理&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
</context>
<context>
    <name>upgradeDialog</name>
    <message>
        <location filename="../ui/upgradeDialog.ui" line="13"/>
        <source>System Upgrade</source>
        <translation>システムの更新</translation>
    </message>
    <message>
        <location filename="../ui/upgradeDialog.ui" line="61"/>
        <source>Force Queue Processing</source>
        <translation>強制的にキューを処理する</translation>
    </message>
    <message>
        <location filename="../ui/upgradeDialog.ui" line="68"/>
        <source>Remember my choice</source>
        <translation>この選択を記憶する</translation>
    </message>
    <message>
        <location filename="../ui/upgradeDialog.ui" line="79"/>
        <source>Abort</source>
        <translation>中止</translation>
    </message>
    <message>
        <location filename="../ui/upgradeDialog.ui" line="103"/>
        <source>Show packages...</source>
        <translation>パッケージを見る...</translation>
    </message>
    <message>
        <location filename="../ui/upgradeDialog.ui" line="120"/>
        <source>Add to Queue</source>
        <translation>キューに追加</translation>
    </message>
    <message>
        <location filename="../ui/upgradeDialog.ui" line="131"/>
        <source>Upgrade Now</source>
        <translation>今すぐアップグレード</translation>
    </message>
    <message>
        <location filename="../ui/upgradeDialog.ui" line="153"/>
        <source>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;System-Upgrade&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head&gt;&lt;meta name=&quot;qrichtext&quot; content=&quot;1&quot; /&gt;&lt;style type=&quot;text/css&quot;&gt;
p, li { white-space: pre-wrap; }
&lt;/style&gt;&lt;/head&gt;&lt;body style=&quot; font-family:&apos;Sans Serif&apos;; font-size:10pt; font-weight:400; font-style:normal;&quot;&gt;
&lt;p style=&quot; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;&quot;&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;システムの更新&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../ui/upgradeDialog.ui" line="192"/>
        <source>Packages to Upgrade</source>
        <translation>アップグレードするパッケージ</translation>
    </message>
</context>
</TS>
