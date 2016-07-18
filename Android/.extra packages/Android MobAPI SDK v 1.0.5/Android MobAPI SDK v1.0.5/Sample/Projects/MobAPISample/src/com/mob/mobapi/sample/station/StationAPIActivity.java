/*
 * 官网地站:http://www.mob.com
 * 技术支持QQ: 4006852216
 * 官方微信:ShareSDK   （如果发布新版本的话，我们将会第一时间通过微信将版本更新内容推送给您。如果使用过程中有任何问题，也可以通过微信与我们取得联系，我们将会在24小时内给予回复）
 *
 * Copyright (c) 2013年 mob.com. All rights reserved.
 */


package com.mob.mobapi.sample.station;

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
import com.mob.mobapi.apis.Station;
import com.mob.mobapi.sample.R;
import com.mob.tools.utils.DeviceHelper;

public class StationAPIActivity extends Activity implements OnClickListener, APICallback {
	private EditText etMCC;
	private EditText etMNC;
	private EditText etLAC;
	private EditText etCELL;
	private TextView tvId;
	private TextView tvAddr;
	private TextView tvCell;
	private TextView tvGoogleLat;
	private TextView tvGoogleLng;
	private TextView tvLac;
	private TextView tvLat;
	private TextView tvLng;
	private TextView tvMcc;
	private TextView tvMnc;
	private TextView tvPrecision;

	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_station);
		etMCC  = forceCast(findViewById(R.id.etMCC));
		etMNC  = forceCast(findViewById(R.id.etMNC));
		etLAC  = forceCast(findViewById(R.id.etLAC));
		etCELL = forceCast(findViewById(R.id.etCELL));
		tvId   = forceCast(findViewById(R.id.tvId));
		tvAddr = forceCast(findViewById(R.id.tvAddr));
		tvCell = forceCast(findViewById(R.id.tvCell));
		tvGoogleLat = forceCast(findViewById(R.id.tvGoogleLat));
		tvGoogleLng = forceCast(findViewById(R.id.tvGoogleLng));
		tvLac = forceCast(findViewById(R.id.tvLac));
		tvLat = forceCast(findViewById(R.id.tvLat));
		tvLng = forceCast(findViewById(R.id.tvLng));
		tvMcc = forceCast(findViewById(R.id.tvMcc));
		tvMnc = forceCast(findViewById(R.id.tvMnc));
		tvPrecision = forceCast(findViewById(R.id.tvPrecision));
		findViewById(R.id.btnSearch).setOnClickListener(this);

		DeviceHelper device = DeviceHelper.getInstance(this);
		etMCC.setText(device.getMCC());
		etMNC.setText(device.getMNC());
		etLAC.setText(String.valueOf(device.getCellLac()));
		etCELL.setText(String.valueOf(device.getCellId()));
	}

	public void onClick(View v) {
		// 获取API实例，查询基站详情
		Station api = forceCast(MobAPI.getAPI(Station.NAME));
		int mcc = 0;
		try {
			mcc = Integer.parseInt(etMCC.getText().toString().trim());
		} catch (Throwable t) {}
		int mnc = 0;
		try {
			mnc = Integer.parseInt(etMNC.getText().toString().trim());
		} catch (Throwable t) {}
		int lac = 0;
		try {
			lac = Integer.parseInt(etLAC.getText().toString().trim());
		} catch (Throwable t) {}
		int cell = 0;
		try {
			cell = Integer.parseInt(etCELL.getText().toString().trim());
		} catch (Throwable t) {}
		api.getBaseStationDetails(mcc, mnc, lac, cell, this);
	}

	public void onSuccess(API api, int action, Map<String, Object> result) {
		@SuppressWarnings("unchecked")
		HashMap<String, Object> address = (HashMap<String, Object>) result.get("result");
		tvId.setText(com.mob.tools.utils.R.toString(address.get("id")));
		tvAddr.setText(com.mob.tools.utils.R.toString(address.get("addr")));
		tvCell.setText(com.mob.tools.utils.R.toString(address.get("cell")));
		tvGoogleLat.setText(com.mob.tools.utils.R.toString(address.get("googleLat")));
		tvGoogleLng.setText(com.mob.tools.utils.R.toString(address.get("googleLng")));
		tvLac.setText(com.mob.tools.utils.R.toString(address.get("lac")));
		tvLat.setText(com.mob.tools.utils.R.toString(address.get("lat")));
		tvLng.setText(com.mob.tools.utils.R.toString(address.get("lng")));
		tvMcc.setText(com.mob.tools.utils.R.toString(address.get("mcc")));
		tvMnc.setText(com.mob.tools.utils.R.toString(address.get("mnc")));
		tvPrecision.setText(com.mob.tools.utils.R.toString(address.get("precision")));
		if (tvPrecision.getText().length() > 0) {
			String text = tvPrecision.getText().toString();
			String unit = getString(R.string.units_meters);
			tvPrecision.setText(text + unit);
		}
	}

	public void onError(API api, int action, Throwable details) {
		details.printStackTrace();
		Toast.makeText(this, R.string.error_raise, Toast.LENGTH_SHORT).show();
	}
}
