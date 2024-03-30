#include "utils.h"

#include <sass.h>
#include <QStringLiteral>

QString invokeStyleSheetLoad(const QString& qValue)
{
    const auto path    = QStringLiteral("../../../src/assets/style/%1/%1.sass").arg(qValue);
    const auto root    = sass_make_file_context(path.toStdString().c_str());
    const auto context = sass_file_context_get_context(root);
    const auto option  = sass_context_get_options(context);
    sass_option_set_precision(option, 2);
    sass_option_set_output_style(option, SASS_STYLE_COMPACT);
    sass_compile_file_context(root);
    if (sass_context_get_error_status(context) != 0) {
        qFatal(sass_context_get_error_message(context));
        return QString();
    }

    const auto styleSheet = QString::fromStdString(sass_context_get_output_string(context));
    sass_delete_file_context(root);
    return styleSheet;
}
