/*
 * 官网地站:http://www.mob.com
 * 技术支持QQ: 4006852216
 * 官方微信:ShareSDK   （如果发布新版本的话，我们将会第一时间通过微信将版本更新内容推送给您。如果使用过程中有任何问题，也可以通过微信与我们取得联系，我们将会在24小时内给予回复）
 *
 * Copyright (c) 2013年 mob.com. All rights reserved.
 */

package com.mob.mobapi.sample.ucache;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import com.mob.mobapi.sample.R;

public class UcacheAPIActivity extends Activity implements OnClickListener {

	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_ucache);
		findViewById(R.id.btnPut).setOnClickListener(this);
		findViewById(R.id.btnGet).setOnClickListener(this);
	}

	public void onClick(View v) {
		switch (v.getId()) {
			case R.id.btnPut: startActivity(new Intent(this, UcachePutActivity.class)); break;
			case R.id.btnGet: startActivity(new Intent(this, UcacheGetActivity.class)); break;
		}
	}
}
