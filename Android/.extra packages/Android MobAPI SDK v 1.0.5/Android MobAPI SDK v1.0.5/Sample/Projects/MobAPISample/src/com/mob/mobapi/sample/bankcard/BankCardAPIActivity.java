/*
 * 官网地站:http://www.mob.com
 * 技术支持QQ: 4006852216
 * 官方微信:ShareSDK   （如果发布新版本的话，我们将会第一时间通过微信将版本更新内容推送给您。如果使用过程中有任何问题，也可以通过微信与我们取得联系，我们将会在24小时内给予回复）
 *
 * Copyright (c) 2013年 mob.com. All rights reserved.
 */

package com.mob.mobapi.sample.bankcard;

import static com.mob.tools.utils.R.forceCast;

import java.util.HashMap;
import java.util.Map;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import com.mob.mobapi.API;
import com.mob.mobapi.APICallback;
import com.mob.mobapi.MobAPI;
import com.mob.mobapi.apis.BankCard;
import com.mob.mobapi.sample.R;

public class BankCardAPIActivity extends Activity implements OnClickListener, APICallback {
	private EditText etBankCardNumber;
	private TextView tvBank;
	private TextView tvBankBin;
	private TextView tvBandbinNumber;
	private TextView tvBankCarName;
	private TextView tvBankCardNumber;
	private TextView tvBankCardType;

	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_bankcard);
		etBankCardNumber = forceCast(findViewById(R.id.etBankCardNumber));
		tvBank           = forceCast(findViewById(R.id.tvBank));
		tvBankBin        = forceCast(findViewById(R.id.tvBankBin));
		tvBandbinNumber  = forceCast(findViewById(R.id.tvBandbinNumber));
		tvBankCarName    = forceCast(findViewById(R.id.tvBankCarName));
		tvBankCardNumber = forceCast(findViewById(R.id.tvBankCardNumber));
		tvBankCardType   = forceCast(findViewById(R.id.tvBankCardType));
		etBankCardNumber.setText("6228482898203884775");
		findViewById(R.id.btnSearch).setOnClickListener(this);
	}

	public void onClick(View v) {
		// 获取API实例，查询银行卡信息
		BankCard api = forceCast(MobAPI.getAPI(BankCard.NAME));
		api.queryBankCard(etBankCardNumber.getText().toString().trim(), this);
	}

	public void onSuccess(API api, int action, Map<String, Object> result) {
		HashMap<String, Object> res = forceCast(result.get("result"));
		tvBank.setText(com.mob.tools.utils.R.toString(res.get("bank")));
		tvBankBin.setText(com.mob.tools.utils.R.toString(res.get("bin")));
		tvBandbinNumber.setText(com.mob.tools.utils.R.toString(res.get("binNumber")));
		tvBankCarName.setText(com.mob.tools.utils.R.toString(res.get("cardName")));
		tvBankCardNumber.setText(com.mob.tools.utils.R.toString(res.get("cardNumber")));
		tvBankCardType.setText(com.mob.tools.utils.R.toString(res.get("cardType")));
	}

	public void onError(API api, int action, Throwable details) {
		details.printStackTrace();
		Toast.makeText(this, R.string.error_raise, Toast.LENGTH_SHORT).show();
	}
}
