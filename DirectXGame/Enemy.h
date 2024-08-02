#include "Player.h"
class Enemy {
public:
	void Initialize(Model* model, uint32_t textureHandle, ViewProjection* viewProjection, const Vector3& position);

	void Update();

	void Draw();

private:

	// ワールド変換データ
	WorldTransform worldTransform_;
	// モデル
	Model* model_ = nullptr;
	// テクスチャハンドル
	uint32_t textureHandle_ = 0u;

	ViewProjection* viewprojection_ = nullptr;

	
	//歩行の速さ
	static inline const float kWalkSpeed = 0.1f;

	//速度
	Vector3 velocity_ = {};

	//最初の角度
	static inline const float kWalkMotionAngleStart = 0;

	// 最後の角度
	static inline const float kWalkMotionAngleEnd = 360.0f;

	//アニメーションの周期となる時間[秒]
	static inline const float kWalkMotionTime = 1.0f;

	float walkTimer_ = 0.0f;


};
