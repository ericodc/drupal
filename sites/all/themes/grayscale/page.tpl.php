<html>
    <head>
    <title><?php print $head_title ?></title>
        <link rel="stylesheet" href="global.css" type="text/css" />
    </head>
<body>
    <div id="container">
        <div id="header">
            <h1><?php print $site_name ?></h1>
            <?php print $header ?>
        </div>
        <?php if ($left) : ?>
        <div id="left">
             <?php print $left ?>
        </div>
            <?php endif; ?>
        <div id="main">
            <?php print $breadcrumb ?>
            <h2><?php print $title ?></h2>
            <?php print $content ?>
        </div>
        <div id="footer">
            <?php print $footer_message ?>
            <?php print $footer ?>
        </div>
    </div>
<?php print $closure ?>
</body>
</html>
