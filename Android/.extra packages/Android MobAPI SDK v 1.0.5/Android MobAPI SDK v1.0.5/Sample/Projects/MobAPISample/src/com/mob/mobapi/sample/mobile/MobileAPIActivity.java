/*
 * 官网地站:http://www.mob.com
 * 技术支持QQ: 4006852216
 * 官方微信:ShareSDK   （如果发布新版本的话，我们将会第一时间通过微信将版本更新内容推送给您。如果使用过程中有任何问题，也可以通过微信与我们取得联系，我们将会在24小时内给予回复）
 *
 * Copyright (c) 2013年 mob.com. All rights reserved.
 */

package com.mob.mobapi.sample.mobile;

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
import com.mob.mobapi.apis.Mobile;
import com.mob.mobapi.sample.R;

public class MobileAPIActivity extends Activity implements OnClickListener, APICallback {
	private EditText etPhone;
	private TextView tvProvince;
	private TextView tvCity;
	private TextView tvCityCode;
	private TextView tvMobileNumber;
	private TextView tvZipCode;
	private TextView tvOperator;

	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_mobile);
		etPhone = (EditText) findViewById(R.id.etPhone);
		tvProvince = (TextView) findViewById(R.id.tvProvince);
		tvCity = (TextView) findViewById(R.id.tvCity);
		tvCityCode = (TextView) findViewById(R.id.tvCityCode);
		tvMobileNumber = (TextView) findViewById(R.id.tvMobileNumber);
		tvZipCode = (TextView) findViewById(R.id.tvZipCode);
		tvOperator = (TextView) findViewById(R.id.tvOperator);
		findViewById(R.id.btnSearch).setOnClickListener(this);
	}

	public void onClick(View v) {
		// 获取API实例，请求手机号码归属地
		Mobile api = (Mobile) MobAPI.getAPI(Mobile.NAME);
		api.phoneNumberToAddress(etPhone.getText().toString().trim(), this);
	}

	public void onSuccess(API api, int action, Map<String, Object> result) {
		@SuppressWarnings("unchecked")
		HashMap<String, Object> address = (HashMap<String, Object>) result.get("result");
		tvProvince.setText(com.mob.tools.utils.R.toString(address.get("province")));
		tvCity.setText(com.mob.tools.utils.R.toString(address.get("city")));
		tvCityCode.setText(com.mob.tools.utils.R.toString(address.get("cityCode")));
		tvMobileNumber.setText(com.mob.tools.utils.R.toString(address.get("mobileNumber")));
		tvZipCode.setText(com.mob.tools.utils.R.toString(address.get("zipCode")));
		tvOperator.setText(com.mob.tools.utils.R.toString(address.get("operator")));
	}

	public void onError(API api, int action, Throwable details) {
		details.printStackTrace();
		Toast.makeText(this, R.string.error_raise, Toast.LENGTH_SHORT).show();
	}

}
