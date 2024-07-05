#include "ViewProjection.h"
#include "WorldTransform.h"

//前方宣言
class Player;

class CameraController {
public:

	//初期化
	void Initialize();

	//更新
	void Update();

	void SetTarget(Player* target) { target_ = target; };

	void Reset();

	private: 
		//ビュープロジェクション
	    ViewProjection viewProjection_;

		Player* target_ = nullptr;

		//追従対象とカメラ座標の差(オフセット)
	    Vector3 targetOffset_ = {0, 0, -15.0f};

		WorldTransform* worldTransform_;

};
