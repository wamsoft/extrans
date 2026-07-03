//---------------------------------------------------------------------------
// extrans : 追加トランジション (wave / mosaic / turn / rotate / ripple) プラグイン
//
// 旧来の V2Link/V2Unlink 直書き + windows.h 依存を廃し、simplebinder/v2link.cpp
// のポータブルな V2Link scaffold (onV2Link / onV2Unlink フック) に載せ替えて、
// 全バリアント (WIN / SDL / LIB) でビルドできるようにしたもの。
//
// トランジションハンドラプロバイダ機構 (TVPAddTransHandlerProvider /
// common/visual/TransIntf) は全バリアントで有効なので、本プラグインは generic
// 版でも問題なく動作する。
//---------------------------------------------------------------------------
#include "tp_stub.h"

#include "wave.h"
#include "mosaic.h"
#include "turn.h"
#include "rotatetrans.h"
#include "ripple.h"

//---------------------------------------------------------------------------
// プラグインリンク時の処理
//   simplebinder/v2link.cpp の V2Link から呼ばれる。この時点で
//   TVPInitImportStub は実行済みで、吉里吉里内部 API が使用可能。
//---------------------------------------------------------------------------
bool onV2Link()
{
	// トランジションハンドラプロバイダの登録
	RegisterWaveTransHandlerProvider();
	RegisterMosaicTransHandlerProvider();
	RegisterTurnTransHandlerProvider();
	RegisterRotateTransHandlerProvider();
	RegisterRippleTransHandlerProvider();

	return true;
}
//---------------------------------------------------------------------------
// プラグインアンリンク時の処理
//   simplebinder/v2link.cpp の V2Unlink から呼ばれる。
//---------------------------------------------------------------------------
bool onV2Unlink()
{
	// トランジションハンドラプロバイダの登録削除
	UnregisterWaveTransHandlerProvider();
	UnregisterMosaicTransHandlerProvider();
	UnregisterTurnTransHandlerProvider();
	UnregisterRotateTransHandlerProvider();
	UnregisterRippleTransHandlerProvider();

	return true;
}
//---------------------------------------------------------------------------
