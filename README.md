# Inverse Kinematics Project
インバースキネマティクスを実装する。

# 環境
- openFrameworks v0.9.3
- Visual Studio 2015

# 使用しているaddon
- ofxBvh

# ToDoリスト
## IK実装のタスク
- 尾下さんのプログラムを土台に実装する  
- まず２次元で動かせるように実装　→　３次元に拡張

## IK計算のタスク
####　１．IKターゲットへ向かうベクトルとボーン自身のベクトルを求める　
    - （IKターゲットへ向かうベクトルAとボーン自身のベクトルBが同じ局所座標上に統合するため）  
  - 1-1．局所座標上のIKターゲットの座標から方向ベクトルを求める
  - 1-2．向きを変えたいボーンの現在の局所座標上の方向ベクトルを求める→求めた値の正規化

#### 2. ２つのベクトルが１つに重なるように回転行列を求める(回転軸と回転角度が必要)
  - 2-1．AとBのドット積からBのベクトルをAのベクトルに重ねるための回転量を求める
  - 2-2．回転量から回転角度を求める
  - 2-3．AとBのクロス積からBのベクトルをAに重ねるための回転軸を求める
  - 2-4．求まった回転軸と回転角度から回転行列を求める

#### ３．回転行列を用いてBを回転する

#### ４．先端から順番にループす

#### その他
- マウスコントロールで関節を選択してターゲットの位置を動かせるようにする
- ofxBvhで扱えるようにする

# 使用しているファイル
-
